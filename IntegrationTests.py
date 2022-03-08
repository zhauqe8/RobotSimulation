import glob, os
import subprocess

Simulator='./RobotSimulation'
Data='../TestData'

def runTests():
    tests=[]
    for ifile in glob.glob(Data+'/*.input'):
        root,ext=os.path.splitext(ifile)
        ofile=root+'.output'
        if os.path.exists(ofile):
            tests.append((ifile,ofile))

    for test in tests:
        p=subprocess.Popen([Simulator, test[0]], stdout=subprocess.PIPE)
        output=p.communicate()
        expected=open(test[1]).readlines()
        assert(1==len(expected))
        assert(expected[0].strip()==output[0].decode('utf-8').strip())

if __name__ == "__main__":
    runTests()


