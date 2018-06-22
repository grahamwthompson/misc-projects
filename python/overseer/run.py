from dateutil import parser
import time
import schedule
from multiprocessing import Process

from overseer import app
from overseer.fetch import fetchLogsPass, dumpLogs

def fetch():
    # Load most recent logfile grab from a configuration file
    try:
        print 'loading saved timestamp..'
        cfg = open('recentfetched.cfg')
        saved = parser.parse(cfg.readline())
        last = fetchLogsPass(saved, 'witiko.co', 'root', 'sometimesiwonderaboutentropy')
        with open('recentfetched.cfg', 'w') as cfg:
            cfg.write(last.isoformat(' '))
    except Exception as e:
        print 'no timestamp found starting new...'
        last = fetchLogsPass(None, 'witiko.co', 'root', 'sometimesiwonderaboutentropy')
        with open('recentfetched.cfg', 'w') as cfg:
            cfg.write(last.isoformat(' '))

def runFetch():
    print 'staring run fetch'
    schedule.every(1).minutes.do(fetch)
    while True:
        schedule.run_pending()
        time.sleep(10)


if __name__ == '__main__':
    #p = Process(target=runFetch)
    #p.start()
    dumpLogs()
    app.run('0.0.0.0')
    #p.join()
