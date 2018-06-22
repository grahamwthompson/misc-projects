# this has gotten very messy with a lot of libs to deal with datetime formats and
# timezones as well as multiple conditionals to deal with the None date case and
# gzipped files using boilerplate code, refactor when I have time works for now though

from paramiko import client, AuthenticationException, SSHException
import datetime
import pytz
from dateutil import parser
import os
import gzip
import re

def fetchLogsPass(last, server, user, password):
    sshc = client.SSHClient()
    sshc.set_missing_host_key_policy(client.AutoAddPolicy())
    log_time = datetime.datetime.min.replace(tzinfo=pytz.UTC)
    print 'created the client'
    try:
        print 'about to start the connection'
        sshc.connect(server, username=user, password=password, look_for_keys=False)
        sftpc = sshc.open_sftp()
    except AuthenticationException:
        print 'Authentication Error ' + server
        return 1
    except SSHException:
        print 'SSH Connection Error ' + server
        return 1

    print 'successfully connected to remote server ' + server + '...'
    # Grab all logfiles
    if last == None:
        stdin, stdout, stderr = sshc.exec_command('ls -t /var/log/nginx')
        for log in stdout.read().split('\n'):
            if 'access' in log:
                if '.gz' in log:
                    print 'dealing with .gz...' + log
                    sftpc.get('/var/log/nginx/' + log, os.getcwd() + '/tmp/' + log)
                    with gzip.open(os.getcwd() + '/tmp/' + log, 'rb') as f:
                        # grab the first datetime in the logfile
                        m = re.search('\[(.+?)\]', f.readline())
                        if m:
                            found = m.group(1)
                            stamp = parser.parse(found[:11] + " " + found[12:])
                            if ( (not last) or stamp >= last):
                                if stamp >= log_time:
                                    log_time = stamp

                else:
                    print 'dealing with access.log...' + log
                    sftpc.get('/var/log/nginx/' + log, os.getcwd() + '/tmp/' + log)
                    with open(os.getcwd() + '/tmp/' + log, 'rb') as f:
                        # grab the first datetime in the logfile
                        m = re.search('\[(.+?)\]', f.readline())
                        if m:
                            found = m.group(1)
                            stamp = parser.parse(found[:11] + " " + found[12:])
                            if ( (not last) or stamp >= last):
                                if stamp >= log_time:
                                    log_time = stamp

    else:
        print 'starting from datetime x....'
        stdin, stdout, stderr = sshc.exec_command('ls -t /var/log/nginx')
        for log in stdout.read().split('\n'):
            if 'access' in log:
                if '.gz' in log:
                    print 'dealing with .gz...' + log
                    sftpc.get('/var/log/nginx/' + log, os.getcwd() + '/tmp/' + log)
                    with gzip.open(os.getcwd() + '/tmp/' + log, 'rb') as f:
                        # grab the first datetime in the logfile
                        m = re.search('\[(.+?)\]', f.readline())
                        if m:
                            found = m.group(1)
                            stamp = parser.parse(found[:11] + " " + found[12:])
                            print 'stamp is ' + stamp.isoformat(' ')
                            if ( (not last) or stamp >= last):
                                if stamp >= log_time:
                                    log_time = stamp
                            else:
                                print 'conditional no trigger breaking...'
                                break

                else:
                    print 'dealing with access.log...' + log
                    sftpc.get('/var/log/nginx/' + log, os.getcwd() + '/tmp/' + log)
                    with open(os.getcwd() + '/tmp/' + log, 'rb') as f:
                        # grab the first datetime in the logfile
                        m = re.search('\[(.+?)\]', f.readline())
                        if m:
                            found = m.group(1)
                            stamp = parser.parse(found[:11] + " " + found[12:])
                            print 'stamp is ' + stamp.isoformat(' ')
                            if ( (not last) or stamp >= last):
                                if stamp >= log_time:
                                    log_time = stamp
                            else:
                                print 'conditional no trigger breaking...'
                                break

    sftpc.close()
    return log_time  # have it return the most recent timestamp to write out


def dumpLogs():
    tmp_logs = os.listdir( os.getcwd() + '/tmp' )
    for log in tmp_logs:
        print log
        if '.gz' in log:
            with gzip.open(os.getcwd() + '/tmp/' + log, 'rb') as f:
                for line in f:
                    pass
                    #print line
        else:
            with open(os.getcwd() + '/tmp/' + log, 'rb') as f:
                for line in f:
                    pass
                    #print line
