// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var Home = require("./page/Home.bs.js");
var Link = require("./component/Link.bs.js");
var List = require("bs-platform/lib/js/list.js");
var Cuid = require("cuid");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Counter = require("./components/Counter.bs.js");
var NewTask = require("./page/NewTask.bs.js");
var AllTasks = require("./page/AllTasks.bs.js");
var NotFound = require("./page/NotFound.bs.js");
var TaskPage = require("./page/TaskPage.bs.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");

function createTask(description) {
  return /* record */[
          /* id */Cuid(),
          /* description */description,
          /* finished */false
        ];
}

function reducer(state, action) {
  if (action.tag) {
    var id = action[0];
    var new_tasks = List.map((function (t) {
            var match = t[/* id */0] === id;
            if (match) {
              return /* record */[
                      /* id */t[/* id */0],
                      /* description */t[/* description */1],
                      /* finished */!t[/* finished */2]
                    ];
            } else {
              return t;
            }
          }), state[/* tasks */0]);
    return /* record */[/* tasks */new_tasks];
  } else {
    return /* record */[/* tasks : :: */[
              createTask(action[0]),
              state[/* tasks */0]
            ]];
  }
}

function App(Props) {
  var match = Props.name;
  var name = match !== undefined ? Caml_option.valFromOption(match) : "World";
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  var match$1 = React.useReducer(reducer, /* record */[/* tasks : :: */[
          createTask("Test"),
          /* :: */[
            createTask("Another test"),
            /* [] */0
          ]
        ]]);
  var dispatch = match$1[1];
  var addTask = function (description) {
    return Curry._1(dispatch, /* AddTask */Block.__(0, [description]));
  };
  var toggleTask = function (id) {
    return Curry._1(dispatch, /* ToggleTask */Block.__(1, [id]));
  };
  var match$2 = url[/* path */0];
  var tmp;
  var exit = 0;
  if (match$2) {
    switch (match$2[0]) {
      case "task" : 
          var match$3 = match$2[1];
          if (match$3) {
            if (match$3[1]) {
              exit = 1;
            } else {
              tmp = React.createElement(TaskPage.make, {
                    id: match$3[0]
                  });
            }
          } else {
            tmp = React.createElement(NewTask.make, {
                  addTask: addTask
                });
          }
          break;
      case "tasks" : 
          if (match$2[1]) {
            exit = 1;
          } else {
            tmp = React.createElement(AllTasks.make, {
                  tasks: match$1[0][/* tasks */0],
                  toggleTask: toggleTask
                });
          }
          break;
      default:
        exit = 1;
    }
  } else {
    tmp = React.createElement(Home.make, { });
  }
  if (exit === 1) {
    tmp = React.createElement(NotFound.make, { });
  }
  return React.createElement(React.Fragment, undefined, React.createElement("nav", undefined, React.createElement(Link.make, {
                      href: "./",
                      text: "Home"
                    }), React.createElement(Link.make, {
                      href: "./task",
                      text: "Add Task"
                    }), React.createElement(Link.make, {
                      href: "./tasks",
                      text: "Tasks"
                    })), React.createElement("h1", undefined, "Hi " + ((
                    name !== undefined ? name : "World"
                  ) + "!")), React.createElement(Counter.make, { }), React.createElement("main", undefined, tmp));
}

var make = App;

exports.createTask = createTask;
exports.reducer = reducer;
exports.make = make;
/* Home Not a pure module */
