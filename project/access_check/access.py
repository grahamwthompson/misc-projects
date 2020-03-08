#!/usr/bin/env python

import click, os, json, time

def formatTimestamp(stamp):
    return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(stamp))

print('Check a folder for modifications/access or checkpoint a folder for later comparison')

# command line arguments should be put here somewhere 
@click.group()
def access():
    pass

@click.command()
@click.argument('folder')
@click.argument('checkpoint_file')
def checkpoint(folder, checkpoint_file):
    click.echo('checkpoint function')
    
    with open(checkpoint_file, 'w') as cf:
        checkpoints = {}
        
        for root, dirs, files in os.walk(".", topdown=False):
            for name in files:
                config_line = {}
                stat = os.stat(os.path.join(root,name))
                config_line['name'] = name
                config_line['size'] = stat.st_size
                config_line['access_time'] = stat.st_atime
                config_line['modification_time'] = stat.st_mtime
                config_line['creation_time'] = stat.st_ctime
                
                checkpoints[name] = config_line

            for name in dirs:
                config_line = {}
                stat = os.stat(os.path.join(root,name))
                config_line['name'] = name
                config_line['size'] = stat.st_size
                config_line['access_time'] = stat.st_atime
                config_line['modification_time'] = stat.st_mtime
                config_line['creation_time'] = stat.st_ctime
                
                checkpoints[name] = config_line
        
        cf.write(json.dumps(checkpoints))

@click.command()
@click.argument('folder')
@click.argument('checkpoint_file')
def check(folder, checkpoint_file):
    click.echo('check access against checkpoint')
    
    checkpoints = {}
    with open(checkpoint_file, 'r') as cf:
        checkpoints = json.load(cf)

    print(checkpoints)
    for root, dirs, files in os.walk(".", topdown=False):
        for name in files:
            if name in checkpoints:
                # check for file differences
                info = checkpoints[name]
                stat = os.stat(os.path.join(root,name))
                changed = False
                access_string = name + ': '

                if info['access_time'] != stat.st_atime:
                    changed = True
                    access_string += 'accessed - {} '.format(formatTimestamp(stat.st_atime))
                if info['modification_time'] != stat.st_mtime:
                    changed = True
                    access_string += 'modified - {} '.format(formatTimestamp(stat.st_mtime))
                if info['creation_time'] != stat.st_mtime:
                    changed = True
                    access_string += 'created - {} '.format(formatTimestamp(stat.st_ctime))
                
                if changed:
                    click.echo(access_string)

            else:
                click.echo('{} - added'.format(name))


access.add_command(checkpoint)
access.add_command(check)

if __name__ == '__main__':
    access()


# if checkpointing go here 

# # create a new checkpoint file to store our checkpoint data
# # recursively itterate through all files in the given directory and output their name, size, 
# # created, modified, and accessed dates to the checkpoint file (maybe a hash too)


# if checking for changes go here 

# # load our specified checkpoint file 

# # recursively itterate through all files and check for any differences between their checkpoint 
# # created, modified and accessed dates and their current ones
# # also list files that were deleted or added
