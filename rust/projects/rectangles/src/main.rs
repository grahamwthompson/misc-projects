#[derive(Debug)]
struct Rectangle {
    width: u32,
    length: u32,
}

impl Rectangle{
    fn area(&self) -> u32 {
        self.width * self.length
    }

}

fn main() {
    let length = 30;
    let width = 50;

    let rect = Rectangle {width:50, length:20};

    println!("Rectangle: {:?}", rect);
    println!("area is: {}",
             rect.area()
             );
}

fn area(rectangle: &Rectangle ) -> u32 {
    rectangle.length * rectangle.width
}
