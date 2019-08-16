fn main() {
  
    mutable_test();
    ownership_test();

    // initialize a mutable unsigned 8 bit integer
    let mut x:u8 = 5;
    x = 8;
    
    {
        // add an immutable reference to x
        //let y: &mut u8 = &mut x;
        let y = &mut x;

        //println!("x:{} y:{}", x, y);

        *y += 1;
    }
   
    // println! uses immutable references to variables to access their
    // values so we can't do a println!("{}",x) while a &mut to the same 
    // variable is in scope/not dropped
    println!("x:{}", x);
    println!("x:{}", x);
    
}

fn mutable_test(){
    // declare and initialize heap mem var
    let mut s1 = String::from("goodbye");
    
    println!("{}", s1);
    
    //let r1 = &mut s1;
    let r1 = &s1;
    
    // can't mutate a variable that has any sort of active borrow
    //s1 = String::from("nope nope");
    println!("{}", s1);
}

fn ownership_test() {
    let s1 = String::from("hello");
    
    // even if we have it go out of scope s1 does not get ownership back looks like
    {
    let s2 = s1;
    }

    //println!("{}", s1);
}
