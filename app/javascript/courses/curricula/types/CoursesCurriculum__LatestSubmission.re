type t = {
  targetId: string,
  passedAt: option(Js.Date.t),
  evaluatorId: option(string),
};

let decode = json =>
  Json.Decode.{
    targetId: json |> field("targetId", string),
    passedAt:
      (json |> optional(field("passedAt", string)))
      ->Belt.Option.map(DateFns.parseJSON),
    evaluatorId:
      json |> field("evaluatorId", nullable(string)) |> Js.Null.toOption,
  };

let targetId = t => t.targetId;

let hasPassed = t =>
  switch (t.passedAt) {
  | Some(_time) => true
  | None => false
  };

let hasBeenEvaluated = t =>
  switch (t.evaluatorId) {
  | Some(_evaluator) => true
  | None => false
  };

let make = (~pending, ~targetId) => {
  targetId,
  passedAt: pending ? None : Some(Js.Date.make()),
  evaluatorId: None,
};
