#!/usr/bin/env python
import click, os, json, time

def formatTimestamp(stamp):
    return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(stamp))

@click.group()
def access():
    '''Command line tool to check file access metadata'''
    pass

@click.command()
@click.argument('folder')
@click.argument('checkpoint_file')
def checkpoint(folder, checkpoint_file):
    '''Create a checkpoint of access metadata'''
    click.echo('Creating checkpoint for {} at {}'.format(folder, checkpoint_file))

    with open(checkpoint_file, 'w') as cf:
        checkpoints = {}

        for root, dirs, files in os.walk(folder, topdown=False):
            for name in files:
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
    '''Check for access since checkpoint'''
    click.echo('Checking access against checkpoint: \n')

    checkpoints = {}
    with open(checkpoint_file, 'r') as cf:
        checkpoints = json.load(cf)

    for root, dirs, files in os.walk(folder, topdown=False):
        for name in files:
            if name in checkpoints:
                # check for file differences
                info = checkpoints[name]
                stat = os.stat(os.path.join(root,name))
                changed = False
                access_string = root + '/' + name + ': '

                if info['access_time'] != stat.st_atime:
                    changed = True
                    access_string += 'accessed-{} '.format(formatTimestamp(stat.st_atime))
                if info['modification_time'] != stat.st_mtime:
                    changed = True
                    access_string += 'modified-{} '.format(formatTimestamp(stat.st_mtime))
                if info['creation_time'] != stat.st_ctime:
                    changed = True
                    access_string += 'created-{} '.format(formatTimestamp(stat.st_ctime))

                if changed:
                    click.echo(access_string)

            else:
                click.echo('{}/{}: added'.format(root, name))


access.add_command(checkpoint)
access.add_command(check)

if __name__ == '__main__':
    access()
