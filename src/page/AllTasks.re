type tasks = list(Task.task);

[@react.component]
let make = (~tasks, ~toggleTask) => {
  <>
    <h1>{"Tasks" |> React.string}</h1>
    {List.map((t: Task.task) => <Task key=t.id task=t toggleTask />, tasks)
      |> Array.of_list |> React.array}
  </>
}
