[@react.component]
let make = (~handleSubmit) => {
  let (input, setInput) = React.useState(() => "");

  let internalSubmit = e => {
    ReactEvent.Synthetic.preventDefault(e);
    handleSubmit(input);
    setInput(_ => "");
  };

  let internalChange = e => {
    let newInput = ReactEvent.Form.target(e)##value;  
    setInput(_ => newInput);
  };

  <>
    <form onSubmit={internalSubmit}>
      <label htmlFor="task-input">{"Enter a task" |> React.string}</label>
      <input 
        id="task-input" 
        name="task" 
        value=input 
        onChange={internalChange}
      />
      <button type_="submit">{"Submit" |> React.string}</button>
    </form>
  </>
}
