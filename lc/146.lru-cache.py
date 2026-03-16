# hashmap with key --> dll node
# dll nodes in "queue" w/ front being least recently used
# back of dll is most recently used
# w/ get, get the value of the node if it exists in the hashmap
# for put, if not at capacity (new element), then add the node to the back of
# the dll queue && update capacity
#   if at capacity, remove front of the dll queue, update front, and then append
#   new value to the back


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

    def __str__(self):
        return f"{self.key} {self.value}"


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.head = None  # least recently used
        self.tail = None  # most recently used

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self.move_to_tail(key)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key not in self.cache:  # adding a new node
            node = Node(key, value)
            self.append_node_at_tail(node)
            length = len(self.cache)
            if length > self.capacity:
                self.remove_head()
        else:  # updating value
            node = self.cache[key]
            node.value = value
            self.move_to_tail(key)

        # print(self)

    def append_node_at_tail(self, node):  # appends node and updates cache
        if self.head is None and self.tail is None:
            node.next = None
            node.prev = None
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            node.next = None
            self.tail = node
        self.cache[node.key] = node

    def remove_head(self):  # at this point, cache must have at least two elements
        if self.head == self.tail:
            self.head = None
            self.tail = None
            return
        old_head = self.head
        self.head = self.head.next
        self.head.prev = None
        self.cache.pop(old_head.key)

    def move_to_tail(self, key):
        node = self.cache.get(key)
        if self.head == node:
            self.remove_head()
            self.append_node_at_tail(node)
        if self.tail == node:
            return

        # in between two nodes
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node
        self.append_node_at_tail(node)

    def __str__(self):
        cache = f"Cache: {self.cache}"
        dll = ""
        temp = self.head
        while temp is not None:
            dll += f"{temp.value} "
            temp = temp.next
        return dll + "\n" + cache


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
