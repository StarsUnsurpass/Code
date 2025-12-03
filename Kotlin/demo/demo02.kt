open class Shape

class Rectangle(val height: Double, val length: Double): Shape(){
    val perimeter = (height + length) * 2
}

fun main(){
    // val rectangle = Rectangle(5.0, 4.0)
    // println("The perimeter is ${rectangle.perimeter}")

    // var a = 1
    // val s1 = "a is $a"

    // a = 2
    // val s2 = "${s1.replace("is", "was")}, but now is $a"
    // println(s2)

    // println("max of 45829 and 89575 is ${maxOf(45829, 89575)}")

    // val items = listOf("apple", "banana", "orange")
    // for(item in items){
    //     println(item)
    // }

    // for(index in items.indices){
    //     println("item at $index is ${items[index]}")
    // }

    // var index = 0
    // while(index < items.size){
    //     println("item at $index is ${items[index]}")
    //     index++
    // }

    // println(describe(1))
    // println(describe("hello"))
    // println(describe(1000L))
    // println(describe(2))
    // println(describe("other"))

    // val x = 100
    // val y = 99
    // if(x in 1..y+1){
    //     println("fits in range")
    // }

    // val list = listOf("a", "b", "c")
    // if(-1 !in 0..list.lastIndex){
    //     println("-1 is out of range")
    // }
    // if(list.size !in list.indices){
    //     println("list size is out of valid list indices range, too")
    // }

    for(x in 1..10 step 2){
        print(x)
        print(" ")
    }
    println()

    for(x in 9 downTo 0 step 3){
        print(x)
        print(" ")
    }
}

// fun describe(obj: Any): String =
//     when(obj){
//         1           -> "one"
//         "hello"     -> "greeting"
//         is Long     -> "Long"
//         !is String  -> "not a string"
//         else        -> "unknown"
//     }


// fun maxOf(a: Int, b: Int): Int{
//     if(a > b){
//         return a
//     }
//     else{
//         return b
//     }
// }