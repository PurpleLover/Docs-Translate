## Intro
This page describes how to use SignalR's methods on both Client/Server.
### Naming Convention
* Client: Pascal. Example: `func sendNude()`
* Server: default/pascal. Example: `func SendNude()`
Server can still use default, and Client auto recognize that method.

## Client
### Example
Scroll to last page of Client (usually last of `.cshtml` file) and paste this
```
@section scripts{
  <script src="~/Scripts/jquery.signalR-2.3.0.min.js"></script>
  <script src="~/signalr/hubs"></script>
  <script>
    $(function (){
      // Reference the auto-generated proxy for the hub.
      var view = $.connection.viewHub; // viewHub is the name of class ViewHub created on Server (Hub)
      view.client.send = function(params) {}
      
      $.connection.hub.start().done(function(){
        view.server.send(params);
      });
    });
  </script>
}
```
If your `_Layout` doesn't have section `scripts`, insert this to nearly the end of your `_Layout`
```
@RenderSection("scripts", required: false)
```
### Explanation:
* `view.client.send = function(params) {}` - Declare method to receive `params` emitted from Server (Hub)
* `view.server.send(params);` - Call method on Server (Hub)

## Server
### Hub
Assume we have a `Hub.cs` on the floor of project (meaning it is in no folder), let's see this example:
```
public void Send(string message, bool status = false, int usecase = 0) {
  Clients.All.Send(string message, bool status = false, int usecase = 0);
}
```
Explaination
* `Send(params)` - Declare method to receive `params` emitted from Client
* `Clients.All.Send(params);` - Emit `params` to All Client (and Call Client method which has been declared before)
### Controller
To call from Controller, use this inside `Create()` or `Edit()` methods,
```
var connection = GlobalHost.ConnectionManager.GetHubContext<ViewHub>();
connection.Clients.All.Send("Cập nhật bài viết", true, USECASE_CONSTANT.CONTENT_PARTS);
```

## Other Usages
* See [Working with Groups](https://docs.microsoft.com/en-us/aspnet/signalr/overview/guide-to-the-api/working-with-groups)
* Or see other pages written by me
