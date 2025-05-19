export interface IStack<T> {
  /**
   * Push data on top of the stack
   * @param data
   */
  push(data: T): void;

  /**
   * Pop & return the most recently added item from the stack
   */
  pop(): T | null;

  /**
   * Get the number of items in the stack
   */
  size(): number

  /**
   * Is the stack empty?
   */
  isEmpty(): boolean
}
