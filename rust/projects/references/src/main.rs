fn main() {
    println!("Hello, world!");

    // declare a reference
    let mut x: u32 = 5;
    let y: &u32 = &x;
    let z: &u32;

    // can we modify copy types with references?
    let rx: &u32 = &x;
    let rx2: &mut u32 = &mut x;
    //let rx3: &mut u32 = &mut x;
    println!("{}", rx2);

    // mix mutable and immutable references
    let mut s = String::from("hello");
    let r1 = &s; // no problem
    let r2 = &s; // no problem
    let r3 = &s; // BIG PROBLEM

println!("{}, {}, and {}", r1, r2, r3);

    let mut x = String::from("stuff stuff");
    borrower(&mut x);  // can have one mutable reference but no more
}


fn borrower(my_string: &mut String){
    my_string.push_str(" and more stuff");
    println!("{}", my_string)
}
