
# Studies on Angular

## Preparation  

1. Download and install [node](https://nodejs.org/en/).

2. Install angular-cli: 

```
npm install -g @angular/cli
```

Obs.: On Windows client computers, the execution of PowerShell scripts may be disabled by default. To allow the execution of PowerShell scripts, which is needed for npm global binaries, you must set the following execution policy:

```
Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy RemoteSigned
```

[**no message was shown in my computer**] Then, carefully read the message displayed after executing the command and follow the instructions. Make sure you understand the implications of setting an execution policy. 

## Starting a new project 

Create a workspace and initial application:

```
ng new my-app
```

The ng new command prompts you for information about features to include in the initial app. Accept the defaults by pressing the Enter or Return key.

The Angular CLI installs the necessary Angular npm packages and other dependencies. This can take a few minutes.

The CLI creates a new workspace and a simple Welcome app, ready to run.

## Running the App 

```
cd my-app
ng serve --open
```

The ng serve command launches the server, watches your files, and rebuilds the app as you make changes to those files.

The --open (or just -o) option automatically opens your browser to http://localhost:4200/.

## Creating Components 

From the project root: 

```
ng generate component product-alerts
```

It generates a directory in the apps/ with the same name as the component, along with .html, .ts, .css and .specs.ts (test) files.

## Basic Syntax 

**Structural directives** shape or reshape the DOM's structure, by adding, removing, and manipulating elements. With `*ngFor`, the `<div>` repeats for each product in the list. 

```
<div *ngFor="let product of products">
</div>
```

Another example is the use of `*ngIf` to create the `<p>` tag only if the description exists. 

```
<p *ngIf="product.description">
    ... 
</p>
```

**Interpolation** `{{ }}` lets you render the property value as text. The `{{ product.name }}` statement shows the product name: 

```
<h3> {{ product.name }} </h3>
```

**Property binding** `[ ]` lets you use the property value in a template expression. Set the title to be the product's name, as follows:

```
<a [title]="product.name + ' details'">
      ...
</a>
```

Hover over a product name to see the bound name property value.

**Event binding** uses a set of parentheses, `( )`, around the event, as in the `(click)` event on the `<button>` element.

```
<button type="button" (click)="share()">
Share
</button>
```

