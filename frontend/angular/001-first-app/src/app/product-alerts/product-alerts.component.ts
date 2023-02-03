import { Component, Input, Output, EventEmitter } from '@angular/core';
import { Product } from '../products';

// The @Component() decorator indicates that the following class is a component. @Component() also provides metadata about the component, including its selector, templates, and styles.
@Component({
  selector: 'app-product-alerts',
  templateUrl: './product-alerts.component.html',
  styleUrls: ['./product-alerts.component.css']
})
export class ProductAlertsComponent {
  // The @Input() decorator indicates that the property value passes in from the component's parent, ProductListComponent.
  @Input() product!: Product;
  
  // Configuring ProductAlertsComponent with an @Output() allows the ProductAlertsComponent to emit an event when the value of the notify property changes. See also the events in src/app/product-alerts/product-alerts.component.html and also in src/app/product-list/product-list.component.html.
  @Output() notify = new EventEmitter();
}
