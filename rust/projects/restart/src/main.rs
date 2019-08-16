fn enum_test() {
    enum Color {
        Red,
        Green,
        Blue
    }
    
    let c: Color = Color::Red;

    match c {
        Color::Red => println!("reeedd"),
        Color::Green => println!("green"),
        Color::Blue => println!("bluuue"),
    }
}

fn struct_test() {

    #[derive(Debug)]
    struct User {
        username: String,
        email: String,
        user_id: u32
    }
    
    let user1 = User{
        username: String::from("kinglord"),
        email: String::from("kinglord@gmail.com"),
        user_id: 1
    };

    impl User {
        fn login(&self) -> u32 {
            self.user_id
        }

        // im an associated function which is like a class
        // function i guess, does not take 
        fn spin(n: u32) {
            let mut x: u32 = n;
            while x > 0 {
                println!("spin");
                x -= 1;
            }
        }
    }

    println!("{:?}", user1);
    println!("login result: {}", user1.login());
    User::spin(2);
    //println!("username: {}\nemail: {}", user1.username, user1.email);
}

fn array_test() {
    let x: [u32; 5] = [1,2,3,4,5];
    println!("array length: {}",x.len());
    
    for number in &x {
        println!("{}", number);
    }

    for number in x.iter() {
        println!("{}", number);
    }
}

fn test(i: u32) -> u32 {
    println!("Function argument: {}", i);
    i
}

fn main() {
    println!("Entry point for our program...");

    
    
    let x: u32 = 5;
    let sum: u32 = loop {
        if x >= 5 {
            break 10;
        }
    };
    println!("sum: {}", sum);

    let y: u32 = test(sum);

    match y {
        1 => println!("one"),
        2 => println!("two"),
        10 => println!("tennnn"),
        _ => println!("any other number")
    };

    println!("Doing an enum test now...");
    enum_test();
    array_test();
    struct_test();
}
