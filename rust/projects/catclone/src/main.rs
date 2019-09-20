use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect(); // declare vector of string init with program args converted 
                                                // from an iterator to a collection (was a generator?) 
    println!("{:?}", args); // special printchar for collection types?
}
