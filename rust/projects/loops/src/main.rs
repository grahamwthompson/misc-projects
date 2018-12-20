fn main() {
    println!("Hello, world!");

    let mut counter: i32 = 0;

    let x: i32 = loop{
        counter += 1;
        if counter > 10{
            break counter;
        }
    };

    println!("Loop Result: {}", x);

    // cant assign based on a while as nicely as you can with a loop
    // this is probably the reason for a seperate syntax, its tricky
    // to get an expression value out of a while which has a default
    // termination that returns no values
    let mut counter: i32 = 0;
    while counter < 10{
        counter += 1
    }
    let y:i32 = counter;

    println!("While Result: {}", y);


    let a = [10, 20, 30, 40, 50];
    //let a = (5,6,7);  does not work with structs

    for element in a.iter() {
        println!("the value is: {}", element);
    }


    for number in (1..4).rev() {
        println!("{}!", number);
    }
    println!("LIFTOFF!!!");
}
