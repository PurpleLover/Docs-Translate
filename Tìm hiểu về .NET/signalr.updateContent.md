## Problem
I wanna update client when it change content, as I review (surf) the web for information, I find that Server should send Message to notify Client to update, not sending all data - in my case is a view - to all Client.

## What I gonna do?

1. client do something
2. trigger changes 
3. send AJAX to server
4. server done the job 
5. send json to client

The problem here is... which client will reiceive the AJAX Load?

My idea is...
1. Specific a group of user
2. Send all

So I choose send all (who viewing the Client where I install SignalR Client Method)

The reference here are (the reason I have to saved likes this is because I don't usually use this platform):
* [Life time](https://docs.microsoft.com/en-us/aspnet/signalr/overview/guide-to-the-api/handling-connection-lifetime-events)
* [API Client Guide](https://docs.microsoft.com/en-us/aspnet/signalr/overview/guide-to-the-api/hubs-api-guide-javascript-client)
* [API Server Guide](https://docs.microsoft.com/en-us/aspnet/signalr/overview/guide-to-the-api/hubs-api-guide-server)
* [How to Update multiple views in 1 broadcast](https://stackoverflow.com/questions/25392965/using-signalr-to-update-multiple-views-with-1-broadcast)
* [Manage Group](https://docs.microsoft.com/en-us/aspnet/signalr/overview/guide-to-the-api/working-with-groups)
* [Sum up Method to Send](https://www.codeproject.com/Tips/1100622/%2FTips%2F1100622%2FSignalR-Difference-Between-Broadcast-To-All-and-Gr)
* [Machine Learning in Excel, the fuck??](https://www.codeproject.com/Articles/1273000/Machine-Learning-in-Excel)
