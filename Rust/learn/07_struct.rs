struct User{
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

struct AlwaysEqual;

fn main(){
    // let user1 = User{
    //     email: String::from("123@456.com"),
    //     username: String::from("Jack"),
    //     active: true,
    //     sign_in_count: 1,
    // };
    // println!("user1's name is {}", user1.username);

    // let mut user2 = User{
    //     email: String::from("321@456.com"),
    //     username: String::from("Tom"),
    //     active: true,
    //     sign_in_count: 2,
    // };
    // user2.email = String::from("135@456.com");
    // println!("user2's email is {}", user2.email);




    // let user1 = User{
    //     email: String::from("123@456.com"),
    //     username: String::from("Jack"),
    //     active: true,
    //     sign_in_count: 1,
    // };

    // let user2 = User{
    //     active: user1.active,
    //     username: user1.username,
    //     email: String::from("342@456.com"),
    //     sign_in_count: user1.sign_in_count,
    // };

    // let user3 = User{
    //     email: String::from("324@456.com"),
    //     ..user1
    // };




    // let user1 = User{
    //     email: String::from("123@456.com"),
    //     username: String::from("Jack"),
    //     active: true,
    //     sign_in_count: 1,
    // };

    // let user2 = User{
    //     active: user1.active,
    //     sign_in_count: user1.sign_in_count,
    //     email: String::from("342@456.com"),
    //     username: String::from("Tony"),
    // };

    // let user3 = User{
    //     email: String::from("324@456.com"),
    //     ..user1
    // };




    // 元组结构体
    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);




    // 类单元结构体
    let subject = AlwaysEqual;
}




// fn build_user2(email: String, username: String) -> User{
//     User{
//         email,
//         username,
//         active: true,
//         sign_in_count: 1,
//     }
// }


// fn build_user1(email: String, username: String) -> User{
//     User{
//         email: email,
//         username: username,
//         active: true,
//         sign_in_count: 1,
//     }
// }