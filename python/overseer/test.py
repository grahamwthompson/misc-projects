from paramiko import client

'''
class ssh:
    client = None
    sftp_client = None

    def __init__(self, address, username, password):
        print "Connecting to server..."
        self.client = client.SSHClient()
        self.client.set_missing_host_key_policy(client.AutoAddPolicy())
        self.client.connect(address, username=username, password=password, look_for_keys=False)
        print "Connecting to SFTP..."
        self.sftp_client= self.client.open_sftp()

    def sendCommand(self, command):
        if(self.client):
            stdin, stdout, stderr = self.client.exec_command(command)
            while not stdout.channel.exit_status_ready():
                # Print data when available
                if stdout.channel.recv_ready():
                    alldata = stdout.channel.recv(1024)
                    prevdata = b"1"
                    while prevdata:
                        prevdata = stdout.channel.recv(1024)
                        alldata += prevdata

                    print str(alldata)
        else:
            print "Connection not opened."


connection = ssh("witiko.co", "root", "sometimesiwonderaboutentropy")
connection.sendCommand("pwd")

connection.sftp_client.get("/var/log/nginx/access.log", "./access.log")

connection.sftp_client.close()
connection.client.close()
'''

sshc = client.SSHClient()
sshc.set_missing_host_key_policy(client.AutoAddPolicy())
print 'created the client'
print 'about to start the connection'
sshc.connect('witiko.co', username='root', password='sometimesiwonderaboutentropy', look_for_keys=False)
stdin, stdout, stderr = sshc.exec_command('pwd')
print stdout.read()
sshc.close()
