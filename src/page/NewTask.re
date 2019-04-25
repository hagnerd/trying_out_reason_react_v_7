[@react.component]
let make = (~addTask) => {
  <>
    <h1>{"Add Task" |> React.string}</h1>
    <TaskInput handleSubmit=addTask />
  </>
};
