module Styles = {
  open Emotion;

  let wrapper = [%css[display(`flex)]];
};

type task = {
  id: string,
  description: string,
  finished: bool,
};

[@react.component]
let make = (~task, ~toggleTask) => {
  <div className=Styles.wrapper>
    <h3>{task.description |> React.string}</h3>
    <input type_="checkbox" onClick={_e => toggleTask(task.id)}/>
  </div>
};
