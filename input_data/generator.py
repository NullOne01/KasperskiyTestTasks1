import sys, os

clear = int(sys.argv[1])
js = int(sys.argv[2])
unix = int(sys.argv[3])
macos = int(sys.argv[4])
errors = int(sys.argv[5])

iterator = 0

for i in range(clear):
    with open(f'file{iterator}_clear.txt', 'w') as f:
        f.write('I\'m clear')
    iterator += 1

for i in range(js):
    with open(f'file{iterator}_js.txt', 'w') as f:
        f.write('<script>evil_script()</script>')
    iterator += 1

for i in range(unix):
    with open(f'file{iterator}_unix.txt', 'w') as f:
        f.write('rm -rf ~/Documents')
    iterator += 1

for i in range(macos):
    with open(f'file{iterator}_macos.txt', 'w') as f:
        f.write('system("launchctl load /Library/LaunchAgents/com.malware.agent")\n')
    iterator += 1

for i in range(errors):
    with open(f'file{iterator}_error.txt', 'w') as f:
        f.write('Try to read me, bitch!')
    os.chmod(f'file{iterator}_error.txt', 0)
    iterator += 1
