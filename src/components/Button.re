module Style = {
  open Emotion;

  let button = [%css [
    color(`hex("e17a00")),
    backgroundColor(`hex("2b3a5d")),
    border(`px(0), `solid, `hex("e17a00"))
  ]];
}

[@react.component]
let make = (~handleClick, ~children) => {
  <button className=Style.button onClick={_e => handleClick()}>children</button>
}
