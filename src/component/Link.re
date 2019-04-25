[@react.component]
let make = (~href, ~text) => {
  let handleClick = (href, event) => {
    if (!ReactEvent.Mouse.defaultPrevented(event)) {
      ReactEvent.Mouse.preventDefault(event);
      ReasonReact.Router.push(href)
    };
  };
  <>
    <a href onClick={e => handleClick(href, e)}>{text |> React.string}</a>
  </>
};
