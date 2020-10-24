const path = require("path");
const fs = require("fs");

const files = [
  {
    in: "src/Encoding/Encoding_BuildElementMapping.bs",
    out: "src/Encoding/Encoding_ElementMapping.js",
  },
  {
    in: "src/Encoding/Encoding_BuildUnitMapping.bs",
    out: "src/Encoding/Encoding_UnitMapping.js",
  },
];

files.forEach((file) => {
  const { mapping, reverseMapping } = require(path.join(__dirname, file.in));

  const js = [
    `export const mapping = ${JSON.stringify(mapping)};`,
    `export const reverseMapping = ${JSON.stringify(reverseMapping)};`,
  ].join("\n");

  fs.writeFileSync(path.join(__dirname, file.out), js);
});
