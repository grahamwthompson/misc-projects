

fn main() {
    println!("Hello, world!");
    {
    let a = String::from("hello");
    let b = borrower(a);  // transfers ownership to function borrower then returns to new var b
    println!("this should work {}", b);
    
    if(b == "hello"){
        println!("the string comparison worked");
    }
    if(String::from("hello") == "hello"){
        println!("this string comparison also worked");
    }

    match &*b {
        "hello" => println!("match comparison worked"),
        _ => println!("well its not hello"),
    }
    //owner(b);
    //println!("this does not work: {}", b);  // function took ownership and does not give it back

    }
}

// I take strings and dont give them back haha
fn owner(x:String){
}

fn borrower(x:String) -> String{
    return x;
}
