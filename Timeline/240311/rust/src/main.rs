use crate::linked_list::LinkedList;
fn main() {
    let mut list = LinkedList::new();
    list.push(1);
    list.push(2);
    list.push(3);
    println!("{:?}", list.pop());
    println!("{:?}", list.pop());
    println!("{:?}", list.pop());
    println!("{:?}", list.pop());
    list.push(4);
    list.push(5);
}
