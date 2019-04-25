[@react.component]
let make = () => {
  /* let (count, setCount) = React.useState(() => 0); */
  let (count, inc, dec, reset) = UseCount.useCount();

  <>
    <h1>
      {"Current Count: " ++ count->string_of_int |> React.string}
    </h1>
    <Button handleClick=inc>
      {"Increment" |> React.string}
    </Button>
    <Button handleClick=dec>
      {"Decrement" |> React.string}
    </Button>
    <Button handleClick=reset>
      {"Reset" |> React.string}
    </Button>
  </>
}
