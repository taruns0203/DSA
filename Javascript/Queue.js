class Queue {
  constructor() {
    this.item = [];
  }

  enqueue(value) {
    this.item.push(value);
  }

  dequeue() {
    return this.item.shift();
  }

  size() {
    return this.item.length;
  }

  isEmpty() {
    return this.item.length === 0;
  }
}

class QueueLinkList {}

let queue = new Queue();
queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(3);

console.log(queue.dequeue());
