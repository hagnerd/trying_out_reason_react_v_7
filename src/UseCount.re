let useCount = () => {
  let (count, setCount) = React.useState(() => 0);

  let inc = () => setCount(c => c + 1);
  let dec = () => setCount(c => c - 1);
  let reset = () => setCount(_ => 0);

  (count, inc, dec, reset)
}
