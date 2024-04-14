fn main(){
  let array_static: [u8] = [1, 2, 3, 4];
  let mut pointer: *[u8];
  let mut count: u8;
  let mut array_dynamic: *u8;
  pointer = array_static;
  println("%d %d\n", array_static[0], *pointer);
}
