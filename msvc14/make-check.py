r"""
Run Link Grammar Python scripts using the build target locations.

This program sets PYTHONPATH and PATH, and uses Python2 or Python3
to run the script, as needed.

This program is designed to reside in this directory.
It reads Local.props in order to find Python's EXE location.
It also generates relative PYTHONPATH and PATH.
In case it is desired to move it to another directory, there is a need to
change the related variables.

The default script directory is binding\python-examples and the default script
to run is tests.py.  In order to run the file example.py there, the following
can be used:
console-prompt>make-check.py x64\Debug\Python2 example.py
The following starts an interactive python program:
console-prompt>make-check.py x64\Debug\Python2 ""
"""
from __future__ import print_function
import os
import sys
import re

local_prop_file = 'Local.props' # In this directory
scriptdir = r'..\bindings\python-examples'
pyscript = 'tests.py'
os.environ["LINK_GRAMMAR_DATA"] = r'..' # "data" in the parent directory

def error(msg):
    if msg:
        print(msg)
    prog = os.path.basename(sys.argv[0])
    print("Usage: ", prog, '[python_flag] PYTHON_OUTDIR [script.py] [script_args]')
    print(r'\tOUTDIR is in the format of "x64\Debug\Python2"')
    sys.exit(1)

local_prop = {}
def read_props(vsfile):
    """ Read all the User Macros from the local properties file. """
    vs_f = open(vsfile, 'r')
    macdef_re = re.compile(r'<(\w+)>([^<]*)<')
    for line in vs_f:
        read_m = re.search(macdef_re, line)
        if None == read_m:
            continue
        if 2 != len(read_m.groups()):
            error('Bad line in "{}": {}'.format(vsfile, line))
        local_prop[read_m.group(1)] = read_m.group(2)
    if not local_prop:
        error('No properties found in {}.'.format(vsfile))

NODEFAULT = object()
prop_re = re.compile(r'\$\((\w+)')
def get_prop(prop, default=NODEFAULT):
    """
    Resolve a macro definition.
    """
    prop_val = local_prop.get(prop, None)
    if None == prop_val:
        if default is NODEFAULT:
            error('Property "{}" not found in {}' .format(prop, local_prop_file))
        return default

    while True:
        prop_m = re.search(prop_re, prop_val)
        if None == prop_m:
            break
        prop_rep = prop_m.group(1)
        prop_repval = local_prop.get(prop_rep, None)
        if None == prop_repval:
            prop_repval = os.getenv(prop_rep)
            if None == prop_repval:
                error('Property "{}" not found in "{}" and also not in the environment'. \
                      format(prop_rep, local_prop_file))
        prop_val = str.replace(prop_val, '$('+prop_rep+')', prop_repval)

    return prop_val


#---
#print('Running by:', sys.executable)

rundir = os.path.dirname(sys.argv[0])
local_prop_file = rundir + '\\' + local_prop_file
read_props(local_prop_file)

if len(sys.argv) < 2:
    error('Missing argument')

pyargs = ''
if len(sys.argv[1]) > 0 and sys.argv[1][0] == '-':
    pyargs = sys.argv.pop(1)

if len(sys.argv) < 2:
    error('Missing argument')

outdir = rundir + '\\' + sys.argv.pop(1)
if not os.path.isdir(outdir):
    error('Directory "{}" doesn\'t exist'.format(outdir))

m = re.search(r'(.*)\\(.*)$', outdir)
if not m or len(m.groups()) != 2:
    error('Invalid output directory "{}"'.format(outdir))
config = m.group(1)
pydir = m.group(2).upper()

pyexe = get_prop(pydir+'_EXE')

if len(sys.argv) == 2:
    if sys.argv[1] == '' or sys.argv[1][0] != '-':
        pyscript = sys.argv.pop(1)

if pyscript != '':
    if pyscript[0] not in ('.', '\\'):
        pyscript = rundir + '\\' + scriptdir + '\\' + pyscript

args = ''
if len(sys.argv) >= 2:
    args = ' '.join(sys.argv[1:])

path = os.environ["PATH"]
dllpath = get_prop('LG_DLLPATH')
# For DLLs - linkgrammar-*.dll and regex.dll
os.environ["PATH"] = ('{};{};{}').format(config, dllpath, path)
#print("PATH=" + os.environ["PATH"])

# For linkgrammar.py, clinkgrammar.py and _clinkgrammar.pyd
os.environ["PYTHONPATH"] = \
    rundir + '\\' + r'..\bindings\python;{}'.format(outdir)
print("PYTHONPATH=" + os.environ["PYTHONPATH"])
#print("Searching modules in:\n" + '\n'.join(sys.path))

cmd = ' '.join((pyexe, pyargs, pyscript, args))
print('Issuing command:', cmd)
os.system(cmd)
