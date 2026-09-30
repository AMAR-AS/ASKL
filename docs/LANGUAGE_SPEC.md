# Ask Language Specification — Foundation

**Language:** Ask / AS Language  
**Source extension:** `.as`  
**Founder / Creator:** Amarjith Singh Kalidasan

## Frontend contract

Ask has one semantic language and multiple human-language surface forms. `.asklang` language packs map surface spellings to canonical tokens before parsing.

## Implemented foundation

- UTF-8 source loading.
- Unicode-friendly identifiers (non-ASCII UTF-8 bytes may participate in identifiers).
- Line and column tracking.
- `//` comments.
- Strings with basic `\\n` and `\\t` escapes.
- Integer and decimal literals.
- `true`, `false`, and `none` literals.
- `var` / `let` declarations and language-pack aliases.
- Assignment.
- Arithmetic and comparison operators.
- Unary `-` and `!`.
- Parenthesized expressions.
- `print(...)`.
- `if` / `else` blocks.
- `while` blocks.
- Semicolon-terminated statements.
- Mixed-language keyword spelling in one file.

## Canonical tokens

`PRINT`, `VAR`, `TRUE`, `FALSE`, `NONE`, `IF`, `ELSE`, `WHILE`, `RETURN`.

The current executable subset implements `if`, `else`, and `while`; `return` is reserved for the function milestone.

## Reserved project words

`amar`, `as`, `ask`, and `asika` are reserved project-defined words and cannot be used as ordinary identifiers.

## Canonical grammar subset

```text
program     := statement* EOF ;
statement   := "print" "(" expression ")" ";"
             | "var" IDENT ("=" expression)? ";"
             | expression ";" ;
expression  := assignment ;
assignment  := equality ("=" assignment)? ;
equality    := comparison (("==" | "!=") comparison)* ;
comparison  := term (("<" | ">" | "<=" | ">=") term)* ;
term        := factor (("+" | "-") factor)* ;
factor      := unary (("*" | "/" | "%") unary)* ;
unary       := ("!" | "-") unary | primary ;
primary     := NUMBER | STRING | TRUE | FALSE | NONE | IDENT | "(" expression ")" ;
```

## Semantic invariants

1. Human-language keyword choice does not change program meaning.
2. Unicode identifiers are distinct from keyword aliases.
3. Equivalent surface forms must produce equivalent canonical ASTs.
4. Bytecode execution is the portable semantic reference path.
5. Implemented behavior is documented separately from planned behavior.

This is the foundation specification; future syntax must define canonical semantics first, then add language-pack spellings, parser rules, tests, and runtime behavior.
