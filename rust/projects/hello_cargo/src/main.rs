
const MAX_POINTS: u32 = 500_000; // this is kind of cute can use _ for seperating large numbers

// prints a global constant
fn myFunction() {
    println!("max points {}", MAX_POINTS);
}

// we send an immutable string reference 
fn stringLength(s: &String) -> usize {
    s.len()    
}

fn main() {

    //myFunction();
    println!("Hello, world!");
    let mystr = String::from("hello hello");
    println!("String length is {}", stringLength(&mystr));
}
