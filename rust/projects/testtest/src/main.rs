use std::io;
mod mymod;


struct Cube {
    length: i32,
    width: i32,
    height: i32,
}


fn main() {

    let mut mystr = String::new();
    //io::stdin().read_line(&mut mystr);
   
    //match mystr {

      //  String::from("hello") => println!("well hello to you too!"),
       // String::from("goodbye") => println!("oh no dont go"),
        
    //}
    //
    let num = mymod::add(3,4);
    println!("number = {}", num);
}
