fn main(){
    // let num = 5;

    // if num < 5{
    //     println!("num is smaller than 5");
    // }
    // else{
    //     println!("num is not smaller than 5");
    // }

    // let condition = (6 % 2) == 0;
    // let number = if condition {5} else {6};

    // println!("the number is {}", number);

    // loop{
    //     println!("again !");
    // }

    // let mut count = 0;
    // 'counting_up: loop{
    //     println!("count = {}", count);
    //     let mut remaining = 10;

    //     loop{
    //         println!("remaining = {}", remaining);
    //         if remaining == 9{
    //             break;
    //         }
    //         if count == 2{
    //             break 'counting_up;
    //         }
    //         remaining -= 1;
    //     }

    //     count += 1;
    // }
    // println!("End count = {}", count);

    // let mut counter = 0;

    // let result = loop{
    //     counter += 1;

    //     if counter == 10{
    //         break counter * 2;
    //     }
    // };

    // println!("The result is {}", result);

    // let mut number = 3;

    // while number != 0{
    //     println!("{}", number);

    //     number -= 1;
    // }

    // println!("LIFTOFF!!!");

    // let a = [1, 2, 3, 4, 5];
    // let mut index = 0;

    // while index < 5{
    //     println!("the value is {}", a[index]);

    //     index += 1;
    // }

    // let a = [1, 2, 3, 4, 5];
    
    // for element in a{
    //     println!("the element is {}", element);
    // }

    // for number in (1..4).rev(){
    //     println!("{}", number);
    // }
    // println!("LIFTOFF!");

    let num = 36;
    let mut res = 1;
    let mut tmp = 1;
    let mut index = 0;

    while index < num{
        res += tmp;
        tmp = res - tmp;
        index += 1;
    }

    println!("the result is {}", res);
}