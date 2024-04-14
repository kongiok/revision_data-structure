use std::cell::RefCell;
use std::rc::Rc;

struct Node<T: Debug> {
    data: T,
    next: Option<Rc<RefCell<Node<T>>>>,
}

#[derive(debug)]
pub struct LinkedList<T: Debug> {
    head: Option<Rc<RefCell<Node<T>>>>,
}

impl<T: Debug> LinkedList<T: Debug> {
    pub fn new() -> Self {
        LinkedList { head: None }
    }

    pub fn push(&mut self, data: T) {
        let new_node = Rc::new(RefCell::new(Node {
            data: data,
            next: self.head.clone(),
        }));
        self.head = Some(new_node);
    }

    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|head| {
            #[cfg(debug_assertions)]
            println!("head: {:#?}", head);
            // let head = head.borrow();
            // let data = head.data;
            // self.head = head.next.clone();
            // data
        })
    }
}
