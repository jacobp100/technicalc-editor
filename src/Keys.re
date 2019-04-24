open Types;

let keys: Js.Dict.t(t) = Js.Dict.empty();
Js.Dict.set(keys, "0", `Digit({atomNucleus: "0", superscript: []}));
Js.Dict.set(keys, "1", `Digit({atomNucleus: "1", superscript: []}));
Js.Dict.set(keys, "2", `Digit({atomNucleus: "2", superscript: []}));
Js.Dict.set(keys, "3", `Digit({atomNucleus: "3", superscript: []}));
Js.Dict.set(keys, "4", `Digit({atomNucleus: "4", superscript: []}));
Js.Dict.set(keys, "5", `Digit({atomNucleus: "5", superscript: []}));
Js.Dict.set(keys, "6", `Digit({atomNucleus: "6", superscript: []}));
Js.Dict.set(keys, "7", `Digit({atomNucleus: "7", superscript: []}));
Js.Dict.set(keys, "8", `Digit({atomNucleus: "8", superscript: []}));
Js.Dict.set(keys, "9", `Digit({atomNucleus: "9", superscript: []}));
Js.Dict.set(keys, "A", `Digit({atomNucleus: "A", superscript: []}));
Js.Dict.set(keys, "B", `Digit({atomNucleus: "B", superscript: []}));
Js.Dict.set(keys, "C", `Digit({atomNucleus: "C", superscript: []}));
Js.Dict.set(keys, "D", `Digit({atomNucleus: "D", superscript: []}));
Js.Dict.set(keys, "E", `Digit({atomNucleus: "E", superscript: []}));
Js.Dict.set(keys, "F", `Digit({atomNucleus: "F", superscript: []}));
Js.Dict.set(keys, ".", `DecimalSeparator);
Js.Dict.set(keys, "+", `Operator(Add));
Js.Dict.set(keys, "-", `Operator(Sub));
Js.Dict.set(keys, "*", `Operator(Mul));
Js.Dict.set(keys, "/", `Operator(Div));
Js.Dict.set(keys, "_", `Frac({fracNum: [], den: [], superscript: []}));
Js.Dict.set(keys, "^", `Placeholder([`Placeholder([])]));
Js.Dict.set(keys, "!", `Factorial);
Js.Dict.set(keys, "(", `OpenBracket);
Js.Dict.set(keys, ")", `CloseBracket([]));

let commands: Js.Dict.t(t) = Js.Dict.empty();
Js.Dict.set(commands, "base2", `Base(Bin));
Js.Dict.set(commands, "base8", `Base(Oct));
Js.Dict.set(commands, "base16", `Base(Hex));
Js.Dict.set(commands, "exp", `Magnitude([]));
Js.Dict.set(commands, "sqrt", `Sqrt({rootRadicand: [], superscript: []}));
Js.Dict.set(
  commands,
  "nroot",
  `NRoot({nrootDegree: [], radicand: [], superscript: []}),
);
Js.Dict.set(commands, "abs", `Abs({absArg: [], superscript: []}));
Js.Dict.set(commands, "log", `Function(Log));
Js.Dict.set(
  commands,
  "log2",
  `NLog({nlogBase: [`Digit({atomNucleus: "2", superscript: []})]}),
);
Js.Dict.set(
  commands,
  "log10",
  `NLog({
    nlogBase: [
      `Digit({atomNucleus: "1", superscript: []}),
      `Digit({atomNucleus: "0", superscript: []}),
    ],
  }),
);
Js.Dict.set(commands, "logn", `NLog({nlogBase: []}));
Js.Dict.set(commands, "sin", `Function(Sin));
Js.Dict.set(commands, "arcsin", `Function(Arcsin));
Js.Dict.set(commands, "sinh", `Function(Sinh));
Js.Dict.set(commands, "arcsinh", `Function(Arcsinh));
Js.Dict.set(commands, "cos", `Function(Cos));
Js.Dict.set(commands, "arccos", `Function(Arccos));
Js.Dict.set(commands, "cosh", `Function(Cosh));
Js.Dict.set(commands, "arccosh", `Function(Arccosh));
Js.Dict.set(commands, "tan", `Function(Tan));
Js.Dict.set(commands, "arctan", `Function(Arctan));
Js.Dict.set(commands, "tanh", `Function(Tanh));
Js.Dict.set(commands, "arctanh", `Function(Arctanh));
Js.Dict.set(commands, "i", `ImaginaryUnit([]));
Js.Dict.set(commands, "x", `Variable({atomNucleus: "x", superscript: []}));
Js.Dict.set(commands, "pi", `Constant({constant: Pi, superscript: []}));
Js.Dict.set(commands, "e", `Constant({constant: E, superscript: []}));
Js.Dict.set(
  commands,
  "ans",
  `Variable({atomNucleus: "Ans", superscript: []}),
);
Js.Dict.set(commands, "gamma", `Function(Gamma));
Js.Dict.set(commands, "rand", `Rand([]));
Js.Dict.set(
  commands,
  "randint",
  `RandInt({randIntA: [], b: [], superscript: []}),
);
Js.Dict.set(commands, "npr", `NPR({statN: [], r: []}));
Js.Dict.set(commands, "ncr", `NCR({statN: [], r: []}));
Js.Dict.set(
  commands,
  "differential",
  `Differential({differentialX: [], body: []}),
);
Js.Dict.set(
  commands,
  "integral",
  `Integral({integralA: [], b: [], body: []}),
);
Js.Dict.set(commands, "sum", `Sum({rangeStart: [], rangeEnd: []}));
Js.Dict.set(commands, "product", `Product({rangeStart: [], rangeEnd: []}));
Js.Dict.set(commands, "dot", `Operator(Dot));
Js.Dict.set(commands, "magnitude", `Magnitude([]));
Js.Dict.set(commands, "degree", `Degree);
Js.Dict.set(commands, "arcminute", `ArcMinute);
Js.Dict.set(commands, "arcsecond", `ArcSecond);

let customAtom = (~value as customAtomValue, ~mml) =>
  `CustomAtom({customAtomValue, mml, superscript: []});
