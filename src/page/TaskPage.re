[@react.component]
let make = (~id) => {
  <>
    <h1>{"Task id: " ++ id |> React.string}</h1>
  </>
};
