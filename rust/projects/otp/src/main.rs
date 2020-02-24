use std::env;
use std::fs::File;
use std::io;
use std::io::prelude::*;

extern crate base64;

fn usage(args: &Vec<String>) {
    println!("otp [output-file] [length]");
    println!("{:?}", args);
}

fn parse_configs(args: &[String]) -> (&String, u64) {
    let filename = &args[1];
    let length = &args[2].parse::<u64>();

    let length = *match length {
        Ok(u64) => u64,
        Err(error) => {
            panic!("Could not read integer length from input...");
        },
    };

    (filename, length)
}

fn main() -> std::io::Result<()> {
    println!("Starting the program here");
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        println!("not enough args");
        usage(&args);
    }
    let (filename, length) = parse_configs(&args);

    let random_source = "/dev/urandom";
    let mut random_source = File::open(random_source)?;
    let mut handle = random_source.take(length);
    let mut buffer: Vec<u8> = vec![0; length as usize];
    
    let n = handle.read_exact(&mut buffer)?;
    println!("Read Return: {:?}", n);
    println!("Bytes {:?}", &buffer);

    
    // buffer to b64 string to bytes which are written to filename which is created
    File::create(filename)?.write_all(base64::encode(&buffer).as_bytes()); // macro syntax for doing matches


    println!("Filename: {}", filename);
    println!("Length: {}", length);

    Ok(())
}
