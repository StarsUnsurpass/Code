// 打印出调试信息
#[derive(Debug)]
struct Rectangle{
    width: u32,
    height: u32,
}

fn main(){
    // let width = 10;
    // let height = 20;

    // println!(
    //     "The area of the rectangle is {} square pixels.",
    //     area1(width, height)
    // );




    // let rec1 = (25, 38);

    // println!(
    //     "The area of the rectangle is {} square pixels.",
    //     area2(rec1)
    // );




    // let rec1 = Rectangle{
    //     width: 35,
    //     height: 25,
    // };

    // println!(
    //     "The area of the rectangle is {} square pixels.",
    //     area(&rec1)
    // );




    // let rec1 = Rectangle{
    //     width: 35,
    //     height: 25,
    // };

    // println!("rec1 is {}", rec1);




    // let rec1 = Rectangle{
    //     width: 35,
    //     height: 25,
    // };

    // println!("rec1 is {:?}", rec1);
    // println!("rec1 is {:#?}", rec1);




    let scale = 5;
    let rec1 = Rectangle{
        width: dbg!(15 * scale),
        height: 25,
    };

    dbg!(&rec1);
}



// fn area(rectangle: &Rectangle) -> u32{
//     rectangle.width * rectangle.height
// }


// fn area2(dimensions: (u32, u32)) -> u32{
//     dimensions.0 * dimensions.1
// }


// fn area1(width: u32, height: u32) -> u32{
//     width * height
// }