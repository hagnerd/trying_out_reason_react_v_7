[@react.component]
let make = (~something, ~children) => {
  <>
    <h1>{something |> React.string}</h1>
    <p>children</p>
  </>
}
