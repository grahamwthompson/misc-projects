use std::env;
use std::str::FromStr;
use std::fs::File;
use std::io::prelude::*;

fn usage(args: &Vec<String>) {
    println!("otp [output-file] [length]");
    println!("{:?}", args);
}

fn main() -> std::io::Result<()> {
    println!("Starting the program here");
    let args: Vec<String> = env::args().collect();
    //println!("{:?}", args);

    if args.len() < 3 {
        println!("not enough args");
        usage(&args);
    }

    let filename = String::from(&args[1]);
    let length = &args[2].parse::<i32>()?;
    //let length = match length {
      //  Ok(i32) => i32,
        //Err(error) => {
          //  panic!("Could not read integer length from input...");
        //},
    //};
   
    File::create("bar.txt")?.write_all(b"farewell world"); // macro syntax for doing matches


    println!("Filename: {}", filename);
    println!("Length: {}", length);

    Ok(())
}
