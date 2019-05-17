let rec count = (x, ~from, ~step=1, fn) =>
  switch (Belt.Array.get(x, from)) {
  | Some(v) when fn(v) => count(x, ~from=from + step, ~step, fn)
  | _ => from / step
  };

let isDigit = x =>
  switch (x) {
  | `DigitS(_)
  | `DecimalSeparator => true
  | _ => false
  };

let insertElement = (ast, element, index) => {
  let (ast, elements, nextIndex) =
    switch (element) {
    | `Frac2S =>
      let s = count(ast, ~from=index - 1, ~step=-1, isDigit);
      let e = count(ast, ~from=index + 1, ~step=1, isDigit);
      let (ast, den) = ArrayUtil.splice(ast, ~offset=e - index, ~len=e);
      let (ast, num) = ArrayUtil.splice(ast, ~offset=index - s, ~len=s);
      let frac =
        Belt.Array.concatMany([|
          [|element|],
          num,
          [|`Arg|],
          den,
          [|`Arg|],
        |]);
      (ast, frac, index + 1);
    | `Sqrt1S =>
      let e = count(ast, ~from=index + 1, ~step=1, isDigit);
      let (ast, radicand) = ArrayUtil.splice(ast, ~offset=e - index, ~len=e);
      let elements =
        Belt.Array.concatMany([|[|element|], radicand, [|`Arg|]|]);
      (ast, elements, index + 1);
    | `NRoot2S =>
      let e = count(ast, ~from=index + 1, ~step=1, isDigit);
      let (ast, radicand) = ArrayUtil.splice(ast, ~offset=e - index, ~len=e);
      let elements =
        Belt.Array.concatMany([|[|element|], radicand, [|`Arg|]|]);
      (ast, elements, index + 1);
    | _ =>
      let elements =
        switch (AST_Types.argCountExn(element)) {
        | 0 => [|element|]
        | argCount =>
          let elements = Belt.Array.make(argCount + 1, `Arg);
          Belt.Array.setExn(elements, 0, element);
          elements;
        };
      (ast, elements, index + 1);
    };
  let ast = ArrayUtil.insertArray(ast, elements, index);
  (ast, nextIndex);
};

let insertIndex = (ast: array(AST_Types.t), element: AST_Types.t, index: int) => {
  let ast = AST_Types.normalize(ast);
  if (AST_NormalizationContext.elementIsValid(ast, element, index)) {
    Some(insertElement(ast, element, index));
  } else {
    None;
  };
};

let insertArrayIndex = (ast, elements, index) => {
  let valid =
    Belt.Array.every(elements, element =>
      AST_NormalizationContext.elementIsValid(ast, element, index)
    );
  if (valid) {
    let ast = ArrayUtil.insertArray(ast, elements, index);
    let nextIndex = index + Belt.Array.length(elements);
    Some((ast, nextIndex));
  } else {
    None;
  };
};
