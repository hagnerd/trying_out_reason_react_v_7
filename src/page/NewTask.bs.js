// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var TaskInput = require("../components/TaskInput.bs.js");

function NewTask(Props) {
  var addTask = Props.addTask;
  return React.createElement(React.Fragment, undefined, React.createElement("h1", undefined, "Add Task"), React.createElement(TaskInput.make, {
                  handleSubmit: addTask
                }));
}

var make = NewTask;

exports.make = make;
/* react Not a pure module */
