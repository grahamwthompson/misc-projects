fn main() {
    println!("Hello, world!");
    {
    let a = String::from("hello");
    let b = borrower(a);  // transfers ownership to function borrower then returns to new var b
    println!("this should work {}", b);
    owner(b);
    //println!("this does not work: {}", b);  // function took ownership and does not give it back

    }
}

// I take strings and dont give them back haha
fn owner(x:String){
}

fn borrower(x:String) -> String{
    return x;
}
