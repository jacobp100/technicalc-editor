let createElement = (~attributes=[], element, body) => {
  let attributes =
    attributes->Belt.List.map(((p, v)) => p ++ "=\"" ++ v ++ "\"")
    |> String.concat(" ");
  let head =
    switch (attributes) {
    | "" => "<" ++ element ++ ">"
    | attributes => "<" ++ element ++ " " ++ attributes ++ ">"
    };
  head ++ body ++ "</" ++ element ++ ">";
};

let wrapSuperscript = (~attributes=?, superscript, element) =>
  switch (superscript) {
  | "" => element
  | s => createElement(~attributes?, "msup", element ++ s)
  };

let elementWithIndex =
    (~attributes=[], ~superscript="", element, (i, i', s), body) =>
  switch (superscript) {
  | "" =>
    let attributes = [
      ("id", string_of_int(i) ++ ":" ++ string_of_int(i')),
      ...attributes,
    ];
    createElement(~attributes, element, body);
  | superscript =>
    let base =
      createElement(
        ~attributes=[("id", ":" ++ string_of_int(s)), ...attributes],
        element,
        body,
      );
    createElement(
      ~attributes=[("id", string_of_int(i) ++ ":" ++ string_of_int(i'))],
      "msup",
      base ++ superscript,
    );
  };
