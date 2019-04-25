type action =
  | AddTask(string)
  | ToggleTask(string);

type state = {tasks: list(Task.task)};

let createTask: string => Task.task =
  description => {id: Cuid.cuid(), description, finished: false};

let reducer = (state, action) =>
  switch (action) {
  | AddTask(description) => {
      tasks: [createTask(description), ...state.tasks],
    }
  | ToggleTask(id) =>
    let new_tasks =
      List.map(
        (t: Task.task) => t.id == id ? {...t, finished: !t.finished} : t,
        state.tasks,
      );

    {tasks: new_tasks};
  };

[@react.component]
let make = (~name=Some("World")) => {
  let url = ReasonReact.Router.useUrl();

  let (state, dispatch) =
    React.useReducer(
      reducer,
      {tasks: [createTask("Test"), createTask("Another test")]},
    );

  let addTask = description => dispatch(AddTask(description));
  let toggleTask = id => dispatch(ToggleTask(id));

  <>
    <nav>
      <Link href="./" text="Home" />
      <Link href="./task" text="Add Task" />
      <Link href="./tasks" text="Tasks" />
    </nav>
    <h1>
      {
        "Hi "
        ++ (
          switch (name) {
          | Some(s) => s
          | None => "World"
          }
        )
        ++ "!"
        |> React.string
      }
    </h1>
    <Counter />
    <main>
      {
        switch (url.path) {
        | ["task"] => <NewTask addTask />
        | ["tasks"] => <AllTasks tasks={state.tasks} toggleTask />
        | ["task", id] => <TaskPage id />
        | [] => <Home />
        | _ => <NotFound />
        }
      }
    </main>
  </>;
};
