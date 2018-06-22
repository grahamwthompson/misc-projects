# sqlalchemy models for logfiles and whatever else we need for this application
# not sure how to optimize this best need a table for all the fields in the
# logs themselves, ip, useragent, etc but I also need to associate them with
# the server they came from in the most efficient way possible probably just a
# many to one, where there's a server table that just has its name, sites associated
# with it and some comment field

# server model one to many relationship with log entry models

# log entry model foreign key for server
#  remote address, remote user, local time, request, status code, bytes sent,
#  http referer, http useragent 
