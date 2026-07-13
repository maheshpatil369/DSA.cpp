# Frontend Developer Interview Prep — Full Stack Reference
*Format per question: Q → Best Answer → Why → Common Mistakes → Follow-up → Follow-up Answer → Difficulty → Product-company frequency*

---

## HTML

**Q1. What is semantic HTML and why does it matter?**
**Best Answer:** Semantic HTML uses tags that describe meaning, not just appearance (`<nav>`, `<article>`, `<section>`, `<header>`, `<footer>` instead of generic `<div>`s). It improves accessibility (screen readers navigate by landmark), SEO (crawlers weight semantic content higher), and maintainability (self-documenting markup).
**Why correct:** It ties one concept to three concrete business outcomes (a11y, SEO, DX) instead of a dictionary definition.
**Common Mistakes:** Saying "it looks better" (wrong reason); not knowing screen readers use landmarks to jump between regions.
**Follow-up:** When would you still use a `<div>` over a semantic tag?
**Follow-up Answer:** When the element has no semantic meaning — a generic wrapper purely for styling/layout (e.g., a flex container grouping cards).
**Difficulty:** Easy
**Product companies:** Very common, asked everywhere as a warm-up.

**Q2. How do you make a web app accessible (a11y)?**
**Best Answer:** Use semantic HTML first, add ARIA roles/labels only when native semantics aren't enough, ensure full keyboard navigation (tab order, focus states, `Escape` to close modals), sufficient color contrast (WCAG AA 4.5:1), `alt` text for images, and test with a screen reader (VoiceOver/NVDA) + axe/Lighthouse.
**Why correct:** Shows a layered strategy (native > ARIA) which is the actual WCAG-recommended approach ("no ARIA is better than bad ARIA").
**Common Mistakes:** Sprinkling `aria-*` everywhere instead of fixing semantics; forgetting keyboard-only users; not managing focus on route change/modal open.
**Follow-up:** How do you trap focus inside a modal?
**Follow-up Answer:** Capture `Tab`/`Shift+Tab` inside the modal container, loop focus between first and last focusable element, restore focus to the trigger element on close (or use `<dialog>` with native `showModal()`).
**Difficulty:** Medium
**Product companies:** Increasingly common (Atlassian, Microsoft heavily test this).

**Q3. How does HTML structure affect SEO?**
**Best Answer:** One `<h1>` per page, logical heading hierarchy, semantic landmarks, descriptive `alt`/`title`, meta description, canonical URLs, and server-rendered (or pre-rendered) content so crawlers see real HTML instead of an empty `<div id="root">`.
**Why correct:** Connects markup choices directly to crawlability, which is what SEO actually depends on for JS-heavy apps.
**Common Mistakes:** Assuming SPA + client-side rendering is automatically SEO-friendly; multiple `<h1>`s; missing meta tags.
**Follow-up:** Why can CSR (client-side rendering) hurt SEO?
**Follow-up Answer:** Crawlers may index the initial empty HTML before JS runs, or execute JS with delays/limits — SSR/SSG guarantees content is present in the initial response.
**Difficulty:** Medium
**Product companies:** Common at product/e-commerce companies (Razorpay, Amazon).

**Q4. How do HTML forms handle validation, and what's the difference between client and server validation?**
**Best Answer:** HTML5 provides built-in validation (`required`, `pattern`, `type="email"`, `minlength`) plus the Constraint Validation API (`checkValidity()`, `setCustomValidity()`). Client-side validation is for UX (instant feedback); server-side validation is mandatory for security since client checks can be bypassed.
**Why correct:** Correctly frames client validation as UX-only, not a security boundary — the actual interview trap.
**Common Mistakes:** Believing client-side validation alone is "secure"; not re-validating on the backend.
**Follow-up:** How would you show a custom error message for an invalid field?
**Follow-up Answer:** Use `input.setCustomValidity('message')` combined with the `invalid` event, or build fully custom validation with `aria-invalid` and `aria-describedby` for accessibility.
**Difficulty:** Easy
**Product companies:** Common.

**Q5. Local Storage vs Session Storage vs Cookies — when do you use each?**
**Best Answer:** LocalStorage: persists indefinitely, ~5-10MB, no auto-send to server, good for non-sensitive preferences/cache. SessionStorage: same API, cleared on tab close, good for per-tab temp state. Cookies: small (~4KB), sent with every HTTP request automatically, support `httpOnly`/`secure`/`sameSite` flags — the only option for storing auth tokens safely against XSS (via httpOnly).
**Why correct:** The key interview differentiator is httpOnly cookies being immune to JS/XSS access, which local/session storage are not — this is the security angle interviewers probe.
**Common Mistakes:** Storing JWTs in localStorage "because it's easier" without mentioning XSS risk; not knowing cookies auto-attach to requests (CSRF implication).
**Follow-up:** If you store a JWT in localStorage, what attack are you exposed to, and how do you mitigate it?
**Follow-up Answer:** XSS — any injected script can read localStorage and exfiltrate the token. Mitigate with strict CSP, sanitizing inputs, or better, store the token in an httpOnly cookie and defend against CSRF instead using `sameSite` + CSRF tokens.
**Difficulty:** Medium
**Product companies:** Extremely common, esp. Razorpay/fintech.

**Q6. What is the DOM and how does the browser build it?**
**Best Answer:** The DOM is a tree representation of the HTML document that JS can query/mutate. The browser parses HTML into the DOM tree, CSS into the CSSOM, combines them into the Render Tree, then does Layout (geometry) and Paint (pixels), followed by Composite.
**Why correct:** Shows the full rendering pipeline, not just "it's a tree," which is what's actually being tested.
**Common Mistakes:** Confusing DOM with HTML source; not knowing about CSSOM or the render pipeline.
**Follow-up:** Why does inserting `<script>` in `<head>` without `defer`/`async` block rendering?
**Follow-up Answer:** The parser is synchronous — it must stop, fetch, and execute the script before continuing to build the DOM, blocking rendering. `defer` downloads in parallel and executes after parsing; `async` executes as soon as it's downloaded.
**Difficulty:** Medium
**Product companies:** Common, esp. performance-focused rounds (Google, Meta).

---

## CSS

**Q7. Explain the CSS Box Model.**
**Best Answer:** Every element is a box: content → padding → border → margin. `box-sizing: content-box` (default) makes `width`/`height` apply to content only; `border-box` includes padding+border in that width, which is why most teams globally set `* { box-sizing: border-box }`.
**Why correct:** Ties theory to the actual practical convention used in real codebases.
**Common Mistakes:** Not knowing `box-sizing` exists; miscalculating total element width.
**Follow-up:** Why do margins collapse between sibling block elements, and how do you prevent it?
**Follow-up Answer:** Adjacent vertical margins collapse into the larger one by spec. Prevent it with padding/border on the parent, `display: flex`/`grid` on the parent, or `overflow: hidden`.
**Difficulty:** Easy
**Product companies:** Very common.

**Q8. Flexbox vs Grid — when do you use which?**
**Best Answer:** Flexbox is one-dimensional (row OR column) — ideal for component-level layout: navbars, button groups, centering. Grid is two-dimensional (rows AND columns) — ideal for page-level layout: dashboards, card grids, complex responsive structures. They compose well together.
**Why correct:** Gives the actual decision heuristic (1D vs 2D) instead of listing properties.
**Common Mistakes:** Using Grid for everything or Flexbox for everything without reasoning; not knowing `fr` units or `grid-template-areas`.
**Follow-up:** How do you build a responsive card grid that auto-fills columns without media queries?
**Follow-up Answer:** `grid-template-columns: repeat(auto-fill, minmax(200px, 1fr))` — auto-fills as many 200px+ columns as fit, growing to fill space.
**Difficulty:** Medium
**Product companies:** Very common.

**Q9. Explain `position: static/relative/absolute/fixed/sticky`.**
**Best Answer:** static: default flow. relative: offsets from its own normal position, still occupies space, becomes a positioning context for absolute children. absolute: removed from flow, positioned relative to nearest positioned ancestor (or viewport). fixed: positioned relative to viewport, stays on scroll. sticky: hybrid — acts relative until a scroll threshold, then sticks like fixed within its container.
**Why correct:** Explicitly calls out that `relative` creates a containing block for `absolute` children — the actual trap most candidates miss.
**Common Mistakes:** Not knowing absolute positioning needs a positioned ancestor; confusing fixed vs sticky.
**Follow-up:** Why might `position: sticky` silently fail to work?
**Follow-up Answer:** A parent has `overflow: hidden/auto/scroll`, or the parent's height equals the child's height (no scroll room), or no `top`/`bottom` value is set.
**Difficulty:** Medium
**Product companies:** Very common.

**Q10. Explain CSS specificity and the cascade.**
**Best Answer:** Specificity is calculated as (inline styles, IDs, classes/attributes/pseudo-classes, elements) — roughly a 4-tuple compared left to right. Higher specificity wins regardless of source order; equal specificity falls back to source order (last wins); `!important` overrides all of this (and should be avoided).
**Why correct:** Gives the actual algorithm, not just "IDs beat classes."
**Common Mistakes:** Thinking specificity is purely additive (100 classes ≠ beats one ID); overusing `!important` as a fix.
**Follow-up:** How would you debug a style that "isn't applying" in production?
**Follow-up Answer:** DevTools computed panel to see which rule won and why (strikethrough = overridden), check for higher-specificity or later rules, check load order of stylesheets, check for `!important` elsewhere.
**Difficulty:** Easy
**Product companies:** Very common.

**Q11. How do you approach responsive design?**
**Best Answer:** Mobile-first: base styles for smallest screen, then `min-width` media queries layer up. Use relative units (`rem`, `%`, `vw`), fluid layouts (Flexbox/Grid), `clamp()` for fluid typography, and responsive images (`srcset`/`sizes`, `picture`).
**Why correct:** Mobile-first is the industry-standard approach (smaller CSS payload for mobile, progressive enhancement) — stating it signals real experience.
**Common Mistakes:** Desktop-first with `max-width` overrides (bloats mobile CSS); using fixed `px` everywhere.
**Follow-up:** What does `clamp(1rem, 2vw + 1rem, 3rem)` do and why use it?
**Follow-up Answer:** Fluidly scales a value between a min (1rem) and max (3rem) based on viewport width, avoiding a stack of media queries just for typography scaling.
**Difficulty:** Medium
**Product companies:** Very common.

**Q12. What are CSS custom properties (variables) and how do they differ from Sass variables?**
**Best Answer:** `--primary-color: #333` defined in `:root` or any selector, read via `var(--primary-color)`. Unlike Sass variables (compile-time, static), CSS variables are live in the browser — they cascade, can be scoped per-component, and can be changed at runtime via JS (`el.style.setProperty`), which is exactly how theming/dark mode is implemented.
**Why correct:** The runtime-vs-compile-time distinction is the actual reason CSS variables exist and is the common follow-up trap.
**Common Mistakes:** Treating them as a drop-in Sass variable replacement without mentioning runtime reactivity/theming use case.
**Follow-up:** How would you implement dark mode using CSS variables?
**Follow-up Answer:** Define semantic tokens (`--bg`, `--text`) in `:root`, redefine them under `[data-theme="dark"]` or `.dark`, toggle that attribute/class via JS, and all consuming rules using `var(--bg)` update automatically without re-render.
**Difficulty:** Medium
**Product companies:** Common.

**Q13. How do CSS animations/transitions work, and which properties are cheap to animate?**
**Best Answer:** `transition` animates a property change over time on state change; `@keyframes` + `animation` define multi-step animations independent of state. Only animate `transform` and `opacity` for 60fps performance — they run on the compositor thread and skip layout/paint. Animating `width`, `top`, `left`, etc. triggers layout thrashing.
**Why correct:** The performance angle (compositor-only properties) is what separates a junior from a senior answer here.
**Common Mistakes:** Animating `width`/`height`/`top` causing jank; not knowing `will-change` exists (and its overuse cost).
**Follow-up:** How would you animate a list item sliding in without causing reflow?
**Follow-up Answer:** Animate `transform: translateX()` and `opacity` instead of `left`/`margin`, optionally hint the browser with `will-change: transform` shortly before the animation starts.
**Difficulty:** Medium
**Product companies:** Common in senior rounds.

---

## JavaScript

**Q14. `var` vs `let` vs `const`?**
**Best Answer:** `var` is function-scoped, hoisted and initialized as `undefined`, allows redeclaration. `let`/`const` are block-scoped, hoisted but stay in the "temporal dead zone" until the declaration line, so accessing early throws a `ReferenceError`. `const` prevents reassignment (not mutation — objects/arrays are still mutable).
**Why correct:** Explicitly covers the TDZ, the actual mechanism interviewers want you to name.
**Common Mistakes:** Saying `let`/`const` "aren't hoisted" (they are, just not initialized); thinking `const` makes objects immutable.
**Follow-up:** What does this log? `console.log(x); let x = 5;`
**Follow-up Answer:** `ReferenceError: Cannot access 'x' before initialization` — TDZ, not `undefined` as `var` would give.
**Difficulty:** Easy
**Product companies:** Extremely common.

**Q15. Explain scope and the scope chain.**
**Best Answer:** Scope determines variable visibility: global, function, and block scope. When a variable is referenced, JS looks up the current scope, then its enclosing (lexical) scope, up to global — this chain is the scope chain, determined by where functions are *written*, not called (lexical scoping).
**Why correct:** Nails "lexical" as the key word — scope is determined at write-time, which underpins closures.
**Common Mistakes:** Confusing lexical scope with dynamic/call-time scope.
**Follow-up:** Does JS have block scope for `function` declarations inside `if` blocks?
**Follow-up Answer:** In strict mode/ES6, function declarations are block-scoped, but behavior is inconsistent across engines historically — safest to use function expressions assigned to `let`/`const` for predictable behavior.
**Difficulty:** Easy
**Product companies:** Very common.

**Q16. What is hoisting?**
**Best Answer:** During the compile phase, JS allocates memory for variable and function declarations before execution. `var` declarations are hoisted and initialized to `undefined`; function declarations are hoisted with their full body; `let`/`const` are hoisted but left in TDZ.
**Why correct:** Distinguishes declaration hoisting from full function hoisting — a common gap.
**Common Mistakes:** Saying "code moves to the top" (it doesn't move, it's a two-phase compile/execute model).
**Follow-up:** Is a function *expression* (`const f = function(){}`) hoisted the same way as a function *declaration*?
**Follow-up Answer:** No — the variable `f` is hoisted (as `undefined`, TDZ if `const`/`let`), but the function body assignment happens at runtime, so calling `f()` before that line throws.
**Difficulty:** Easy
**Product companies:** Very common.

**Q17. What is a closure? Give a real use case.**
**Best Answer:** A closure is a function that retains access to its lexical scope's variables even after the outer function has returned. Real use case: creating private state (a counter factory), memoization caches, or debouncing — the inner function "closes over" a variable that persists across calls.
**Why correct:** Pairs the definition with a concrete production use case (what interviewers actually want).
**Common Mistakes:** Giving only the textbook definition with no real-world application; the classic loop+`var`+`setTimeout` bug.
**Follow-up:** Why does `for (var i=0;i<3;i++) setTimeout(()=>console.log(i))` print `3,3,3` instead of `0,1,2`, and how do you fix it?
**Follow-up Answer:** `var` is function-scoped, so all callbacks share the same `i`, which is 3 by the time timers fire. Fix: use `let` (creates a new binding per iteration) or wrap in an IIFE capturing `i` by value.
**Difficulty:** Medium
**Product companies:** Extremely common — classic gotcha.

**Q18. Explain the Event Loop, Call Stack, Microtasks, and Macrotasks.**
**Best Answer:** JS is single-threaded with one Call Stack. Async work (timers, I/O) is handed to Web APIs; when done, callbacks queue up — Promises go to the microtask queue, `setTimeout`/events go to the macrotask (task) queue. After each call stack execution, the Event Loop first drains ALL microtasks, then processes one macrotask, repeating.
**Why correct:** Explicitly states the microtask-before-macrotask priority and "drain all microtasks" rule — the actual thing interviewers test with tricky ordering questions.
**Common Mistakes:** Treating all async callbacks as equal priority; not knowing microtasks fully drain before the next macrotask.
**Follow-up:** What's the output order of: `console.log(1); setTimeout(()=>console.log(2)); Promise.resolve().then(()=>console.log(3)); console.log(4);`
**Follow-up Answer:** `1, 4, 3, 2` — sync code runs first (1,4), then microtask (3), then macrotask (2).
**Difficulty:** Hard
**Product companies:** Extremely common, esp. Meta/Google.

**Q19. Callback vs Promise vs async/await — why did JS evolve this way?**
**Best Answer:** Callbacks led to "callback hell" (nested, hard to handle errors uniformly). Promises flattened this with `.then()` chaining and a single `.catch()` for errors, plus combinators (`Promise.all`, `allSettled`, `race`). `async/await` is syntactic sugar over Promises, letting async code read like sync code with `try/catch` for errors.
**Why correct:** Frames it as an evolution driven by real pain points (readability, error handling), not just syntax preference.
**Common Mistakes:** Thinking async/await is a different concurrency model (it isn't — still Promises under the hood); forgetting `await` in a loop serializes calls that could run in parallel.
**Follow-up:** How do you run 3 independent async calls in parallel with async/await?
**Follow-up Answer:** `const [a,b,c] = await Promise.all([fn1(), fn2(), fn3()])` — kicks off all three immediately instead of awaiting sequentially.
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q20. Explain `this` in JavaScript.**
**Best Answer:** `this` is determined by *how a function is called*, not where it's defined (except arrow functions). Rules in order of precedence: `new` binding → explicit binding (`call`/`apply`/`bind`) → implicit binding (`obj.method()` → `obj`) → default binding (`undefined` in strict mode, global object otherwise). Arrow functions don't have their own `this` — they inherit it lexically from the enclosing scope.
**Why correct:** Gives the precedence order, which resolves ambiguity in every "what does `this` log here" trick question.
**Common Mistakes:** Assuming arrow functions "don't have `this`" (they do — inherited, not absent); losing `this` when passing a method as a callback (`onClick={obj.method}`).
**Follow-up:** Why does a class method lose its `this` when passed as an event handler, and how do you fix it in React?
**Follow-up Answer:** The method is called as a plain function (`handler()`), not `obj.handler()`, so implicit binding is lost. Fix: bind in constructor (`this.handler = this.handler.bind(this)`), use an arrow function class property, or wrap in an inline arrow in JSX.
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q21. Explain `bind`, `call`, and `apply`.**
**Best Answer:** All three explicitly set `this`. `call(thisArg, a, b)` invokes immediately with args listed individually. `apply(thisArg, [a,b])` invokes immediately with args as an array. `bind(thisArg, a, b)` returns a *new function* with `this` permanently bound, invoked later.
**Why correct:** The key distinction (immediate invocation vs returning a bound function) is exactly what's tested.
**Common Mistakes:** Mixing up call/apply argument format; forgetting `bind` returns a new function rather than calling it.
**Follow-up:** How would you borrow the `Array.prototype.slice` method to convert `arguments` into a real array?
**Follow-up Answer:** `Array.prototype.slice.call(arguments)` — calls `slice` with `this` set to the array-like `arguments` object (modern equivalent: `Array.from(arguments)` or rest params).
**Difficulty:** Medium
**Product companies:** Common.

**Q22. Explain the prototype chain and prototypal inheritance.**
**Best Answer:** Every JS object has an internal `[[Prototype]]` link (accessible via `__proto__` or `Object.getPrototypeOf`). Property lookup walks up this chain until found or reaching `null`. `class` syntax is sugar over this — `class B extends A` sets `B.prototype.__proto__ = A.prototype`.
**Why correct:** Explicitly demystifies `class` as sugar over prototypes, which is what senior interviewers want to hear.
**Common Mistakes:** Believing `class` is a fundamentally different inheritance model from prototypes; confusing `prototype` (on constructor functions) with `__proto__` (on instances).
**Follow-up:** What's the output of `Object.create(null)` and why would you use it?
**Follow-up Answer:** Creates an object with no prototype chain at all (no inherited methods like `toString`) — useful for a clean dictionary/map object immune to prototype pollution.
**Difficulty:** Hard
**Product companies:** Common in senior/Google-style rounds.

**Q23. What is event delegation and why use it?**
**Best Answer:** Attach a single listener to a common ancestor instead of individual listeners on many children, using `event.target` to determine which child triggered it (via `.closest()` or matching). Leverages event bubbling. Reduces memory usage and automatically handles dynamically added children.
**Why correct:** Names the underlying mechanism (bubbling) and the two real payoffs (perf + dynamic elements) instead of just "it's more efficient."
**Common Mistakes:** Not knowing bubbling is the mechanism; forgetting some events don't bubble (`focus`, `blur` — use `focusin`/`focusout` instead).
**Follow-up:** You have a table with 10,000 rows, each with a delete button. How do you handle clicks efficiently?
**Follow-up Answer:** One listener on the `<table>` or `<tbody>`, check `event.target.closest('.delete-btn')`, extract the row id from a `data-id` attribute, avoid attaching 10,000 individual listeners.
**Difficulty:** Medium
**Product companies:** Very common.

**Q24. Debouncing vs Throttling?**
**Best Answer:** Debounce delays execution until a pause in events (fires once, after the burst stops) — used for search-as-you-type, resize-end. Throttle guarantees execution at most once per fixed interval regardless of how many events fire — used for scroll handlers, infinite scroll triggers.
**Why correct:** Uses the correct real use case for each (search vs scroll), which is exactly how interviewers verify true understanding vs memorized definitions.
**Common Mistakes:** Mixing up which is which; not being able to implement either from scratch.
**Follow-up:** Implement debounce from scratch.
**Follow-up Answer:**
```js
function debounce(fn, delay) {
  let timer;
  return (...args) => {
    clearTimeout(timer);
    timer = setTimeout(() => fn(...args), delay);
  };
}
```
**Difficulty:** Medium
**Product companies:** Extremely common — expect a live-coding version.

**Q25. What causes memory leaks in JS and how do you detect them?**
**Best Answer:** Common causes: forgotten timers/intervals, detached DOM nodes still referenced in JS, event listeners never removed, closures holding large objects unnecessarily, global variable accumulation. Detect via Chrome DevTools Memory tab — take heap snapshots before/after an action, compare, look for growing "Detached" DOM node counts.
**Why correct:** Lists concrete causes tied to real code patterns, plus the actual tool/workflow to diagnose (heap snapshot diffing).
**Common Mistakes:** Vague "not clearing memory" answers with no mechanism or tooling knowledge.
**Follow-up:** In React, what's a classic memory leak pattern and its fix?
**Follow-up Answer:** Setting state in an async callback after the component unmounted (e.g., a fetch resolves post-unmount). Fix: cleanup function in `useEffect` with an `isMounted`/`AbortController` guard, or cancel the request on unmount.
**Difficulty:** Hard
**Product companies:** Common in senior rounds.

**Q26. How does JS garbage collection work?**
**Best Answer:** Modern engines use mark-and-sweep: starting from GC "roots" (global object, active call stack), the engine marks all reachable objects; anything unreachable is swept/freed. Reference counting alone (old approach) fails on circular references, which mark-and-sweep handles correctly.
**Why correct:** Names the actual algorithm (mark-and-sweep) and explains why it supersedes reference counting.
**Common Mistakes:** Saying "JS just cleans up unused variables" with no mechanism.
**Follow-up:** Can you force garbage collection in JS?
**Follow-up Answer:** No direct API in production JS (V8 exposes `--expose-gc` only in debug/Node flags) — you can only avoid holding references so objects become eligible for collection.
**Difficulty:** Hard
**Product companies:** Occasionally asked, mostly senior/Google.

**Q27. `map` / `filter` / `reduce` — explain and give a `reduce` example that isn't just summing.**
**Best Answer:** `map` transforms each element 1:1 into a new array. `filter` keeps elements matching a predicate. `reduce` folds the array into a single accumulated value — general enough to implement `map`/`filter`/`groupBy`/`flatten` themselves. Example: grouping objects by a key using `reduce` into an object of arrays.
**Why correct:** Showing `reduce` can implement the others demonstrates real depth beyond "it sums numbers."
**Common Mistakes:** Mutating the original array in `map`; forgetting `reduce`'s initial value causes bugs on empty arrays.
**Follow-up:** Implement `groupBy` using `reduce`.
**Follow-up Answer:**
```js
const groupBy = (arr, key) => arr.reduce((acc, item) => {
  (acc[item[key]] ??= []).push(item);
  return acc;
}, {});
```
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q28. Spread vs Rest — what's the difference?**
**Best Answer:** Same `...` syntax, opposite direction. Spread *expands* an iterable into individual elements (`[...arr]`, function call args, object merge `{...obj}`). Rest *collects* multiple arguments/remaining elements into a single array/object (`function f(...args)`, `const [a, ...rest] = arr`).
**Why correct:** "Expand vs collect, direction depends on context" is the precise rule interviewers want stated.
**Common Mistakes:** Thinking they're the same operator with no distinction; not knowing spread on objects only does a shallow copy.
**Follow-up:** Does `{...obj}` do a deep or shallow clone? What's the implication?
**Follow-up Answer:** Shallow — nested objects/arrays are still shared by reference, so mutating a nested property affects both copies. Need `structuredClone()` or a deep-clone utility for true deep copies.
**Difficulty:** Easy
**Product companies:** Very common.

**Q29. Destructuring — give a non-trivial example with defaults and renaming.**
**Best Answer:** `const { data: items = [], user: { name: userName } = {} } = response;` — pulls `data` renamed to `items` with a default empty array, and safely destructures a nested `user.name` renamed to `userName`, defaulting the whole `user` object to `{}` to avoid a crash if `user` is undefined.
**Why correct:** Demonstrates nested destructuring + defaults + renaming together — the realistic pattern used in API response handling.
**Common Mistakes:** Not knowing defaults only apply when the value is `undefined` (not `null` or falsy).
**Follow-up:** What happens if `response.user` is `null` in the example above?
**Follow-up Answer:** It crashes — defaults only kick in for `undefined`, not `null`. Need `user: { name: userName } = {}` guarded further, or `user?.name` with optional chaining, or explicit null coalescing beforehand.
**Difficulty:** Easy
**Product companies:** Common.

---

## TypeScript

**Q30. Interface vs Type — when do you use which?**
**Best Answer:** Both describe object shapes and are largely interchangeable for objects. Prefer `interface` for public API shapes (libraries, props) because it supports declaration merging and is more familiar for OOP-style extension (`extends`). Prefer `type` for unions, tuples, mapped/conditional types, and primitives — things `interface` can't express.
**Why correct:** Gives a real decision rule (capability-based), not "they're basically the same, doesn't matter."
**Common Mistakes:** Claiming they're 100% identical (they're not — declaration merging is interface-only).
**Follow-up:** What is declaration merging and why is it useful?
**Follow-up Answer:** Two `interface` declarations with the same name automatically merge their members — used to extend third-party types (e.g., augmenting Express's `Request` type to add `req.user`).
**Difficulty:** Medium
**Product companies:** Very common if TS is on the JD.

**Q31. What are Generics and why do we need them?**
**Best Answer:** Generics let you write reusable, type-safe code that works across multiple types without losing type information, e.g., `function identity<T>(arg: T): T`. Without generics you'd use `any` (losing type safety) or write duplicate functions per type.
**Why correct:** Explains the actual problem generics solve (type-safe reuse) vs the `any` escape hatch.
**Common Mistakes:** Overusing `any` instead of generics; not constraining generics with `extends` when needed.
**Follow-up:** Write a generic function `pluck<T, K extends keyof T>(arr: T[], key: K): T[K][]`.
**Follow-up Answer:** `function pluck<T, K extends keyof T>(arr: T[], key: K): T[K][] { return arr.map(item => item[key]); }` — `K extends keyof T` constrains `key` to valid property names of `T`, giving full autocomplete/type safety.
**Difficulty:** Medium
**Product companies:** Common in senior/TS-heavy roles.

**Q32. Enums — what are they and what's the caveat with numeric enums?**
**Best Answer:** Enums define a named set of constants (`enum Role { Admin, User }`). Numeric enums are bidirectional at runtime (reverse mapping), which bloats compiled JS. Many teams prefer `as const` union types (`const Role = { Admin: 'ADMIN', User: 'USER' } as const`) for a lighter, tree-shakeable alternative with the same type safety.
**Why correct:** Flags the actual modern-team preference and reasoning (bundle size, tree-shaking) rather than presenting enums as the default best practice.
**Common Mistakes:** Not knowing `as const` objects are a common enum alternative; assuming string and numeric enums behave identically.
**Follow-up:** Why might a linter (like the TS team's own guidance) discourage enums?
**Follow-up Answer:** They generate extra runtime code, aren't erased at compile time like other TS constructs, and interact awkwardly with `isolatedModules`/bundlers — `as const` unions are purely compile-time with zero runtime cost.
**Difficulty:** Medium
**Product companies:** Common.

**Q33. Name and explain 3 Utility Types you use often.**
**Best Answer:** `Partial<T>` — makes all properties optional (useful for update/patch payloads). `Pick<T, K>` — selects a subset of keys (useful for narrowing a large DTO to what a component needs). `Omit<T, K>` — the inverse, excludes keys (useful for stripping sensitive fields like `password` from a response type).
**Why correct:** Ties each utility type to a realistic use case instead of a dry list.
**Common Mistakes:** Only naming them without use cases; not knowing `Required<T>` or `Record<K,V>`.
**Follow-up:** How would you type a function that takes an object and returns it with all fields required except one optional field?
**Follow-up Answer:** `type Result = Required<Omit<T, 'field'>> & Partial<Pick<T, 'field'>>` — combine `Omit`+`Required` for the mandatory fields and `Pick`+`Partial` for the optional one, then intersect.
**Difficulty:** Hard
**Product companies:** Common in senior TS rounds.

---

## React

**Q34. What is the Virtual DOM and why does React use it?**
**Best Answer:** The Virtual DOM is a lightweight JS object tree mirroring the real DOM. On state change, React builds a new VDOM tree, diffs it against the previous one (reconciliation), and applies only the minimal set of real DOM mutations. Real DOM operations are expensive (layout/paint); diffing in JS memory is cheap.
**Why correct:** States *why* it's fast — batched, minimal DOM writes — not just "it's a copy of the DOM."
**Common Mistakes:** Claiming VDOM makes React "faster than vanilla JS" unconditionally (it's about developer ergonomics + batching, not magic speed).
**Follow-up:** What's React's diffing heuristic that makes it O(n) instead of O(n³)?
**Follow-up Answer:** Two assumptions: different element types produce different trees (no deep diff, just replace), and `key` props let React match list items across renders instead of re-diffing by index.
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q35. Why does React need `key` in lists, and what goes wrong with `index` as key?**
**Best Answer:** `key` gives React a stable identity to match elements between renders. Using array index breaks when items are reordered/inserted/deleted — React misassociates state (e.g., an input's typed value) with the wrong item because the *position*, not the item's identity, stayed the same.
**Why correct:** Explains the actual failure mode (state misassociation), a real bug interviewers have seen in production.
**Common Mistakes:** Using `index` as key "because it's easy," or not knowing why it's bad beyond "it's an anti-pattern."
**Follow-up:** When IS index-as-key acceptable?
**Follow-up Answer:** When the list is static, never reordered/filtered/inserted, and has no per-item state (e.g., a fixed list rendered once).
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q36. Explain `useEffect` — dependency array, cleanup, common pitfalls.**
**Best Answer:** `useEffect(fn, deps)` runs `fn` after paint when any value in `deps` changes (empty array = run once on mount; omitted = every render). Returning a function from `fn` is the cleanup, run before the next effect execution and on unmount — used to cancel subscriptions/timers/requests. Pitfall: missing dependencies cause stale closures (effect uses an old value).
**Why correct:** Covers the full lifecycle (mount, update, cleanup) plus the stale closure trap, which is the #1 real-world useEffect bug.
**Common Mistakes:** Disabling the exhaustive-deps lint rule instead of fixing the actual dependency; putting objects/functions in deps without memoizing, causing infinite loops.
**Follow-up:** Your `useEffect` with `[]` deps uses a prop value but it's always stale. Why, and how do you fix it?
**Follow-up Answer:** The closure captured the prop's value at mount time and `[]` means it never re-runs to pick up the new value. Fix: add the prop to the dependency array (correct fix), or use a ref to always read the latest value if you intentionally want mount-only behavior.
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q37. `useMemo` vs `useCallback` — what's the actual difference, and when do they NOT help?**
**Best Answer:** `useMemo(fn, deps)` memoizes a computed *value*; `useCallback(fn, deps)` memoizes a *function reference* (shorthand for `useMemo(() => fn, deps)`). Both only help when (a) the computation is genuinely expensive, or (b) referential stability matters — e.g., preventing a memoized child (`React.memo`) from re-rendering, or preventing an effect from re-firing due to a new function/object reference each render. Overusing them adds memory + comparison overhead for no benefit.
**Why correct:** Explicitly states the "when they DON'T help" caveat, which is what separates senior candidates — most junior answers imply "always memoize."
**Common Mistakes:** Wrapping everything in `useMemo`/`useCallback` by default; not connecting them to `React.memo`'s shallow prop comparison.
**Follow-up:** You wrapped a child in `React.memo` but it still re-renders every time. Why?
**Follow-up Answer:** A prop passed to it is a new reference each render (an inline object/array/function), failing the shallow equality check — wrap that prop's creation in `useMemo`/`useCallback` in the parent.
**Difficulty:** Medium
**Product companies:** Extremely common.

**Q38. Controlled vs Uncontrolled components?**
**Best Answer:** Controlled: form value lives in React state, updated via `onChange`, React is the single source of truth — enables validation/formatting on every keystroke. Uncontrolled: the DOM holds the value, accessed via a `ref` only when needed (e.g., `formRef.current.value`) — simpler, less re-rendering, good for large forms or file inputs.
**Why correct:** Gives the actual trade-off (control/validation vs performance/simplicity) instead of just definitions.
**Common Mistakes:** Not knowing file inputs (`<input type="file">`) can only be uncontrolled; thinking uncontrolled is always "worse."
**Follow-up:** For a form with 50 fields, why might uncontrolled + a form library (like React Hook Form) outperform fully controlled state?
**Follow-up Answer:** Fully controlled means every keystroke re-renders the component (and possibly the whole form); uncontrolled with refs avoids re-renders per keystroke, only reading values on submit/validation, which libraries like React Hook Form leverage for performance.
**Difficulty:** Medium
**Product companies:** Very common.

**Q39. Explain the Context API and when NOT to use it.**
**Best Answer:** Context avoids prop drilling by letting any descendant subscribe to a value via `useContext` without it being passed through every intermediate component. Avoid it for high-frequency updates (e.g., mouse position, form state per keystroke) because *any* context value change re-renders *all* consumers — for that, use a state management library with selective subscriptions (Zustand, Redux with selectors) instead.
**Why correct:** States the real limitation (no selective subscription, all consumers re-render) which is the actual reason Redux/Zustand still exist alongside Context.
**Common Mistakes:** Treating Context as a full Redux replacement for all global state, including frequently-changing data.
**Follow-up:** How do you prevent unrelated consumers from re-rendering when only part of a large context value changes?
**Follow-up Answer:** Split into multiple smaller contexts by concern, or memoize the provider's value, or move to a library with fine-grained subscriptions (Zustand/Jotai/Redux selectors) so components only re-render for the slice they read.
**Difficulty:** Medium
**Product companies:** Very common.

**Q40. Redux Toolkit — why was it created, and what problems does it solve vs classic Redux?**
**Best Answer:** RTK removes classic Redux boilerplate: `createSlice` auto-generates action creators + reducers using Immer under the hood (so you can "mutate" state in reducers safely), `configureStore` sets up good defaults (devtools, thunk, immutability checks), and RTK Query handles data-fetching/caching declaratively, removing the need for hand-written thunks for most API calls.
**Why correct:** Names the concrete mechanism (Immer) and the two big wins (less boilerplate, built-in data fetching) that justify RTK being the official recommended approach today.
**Common Mistakes:** Not knowing Immer is what allows "mutating" draft state; still writing classic switch-based reducers by hand in 2024+.
**Follow-up:** How does RTK Query handle cache invalidation between a mutation (e.g., creating a post) and a query (e.g., list of posts)?
**Follow-up Answer:** Via `tagTypes` — queries provide tags (e.g., `Posts`), mutations invalidate matching tags, which automatically re-triggers any active query subscribed to that tag, refetching fresh data.
**Difficulty:** Hard
**Product companies:** Very common if Redux is on the JD.

**Q41. Explain code splitting, `React.lazy`, and `Suspense`.**
**Best Answer:** Code splitting breaks the JS bundle into smaller chunks loaded on demand instead of one large upfront bundle, improving initial load time. `React.lazy(() => import('./Component'))` dynamically imports a component; `<Suspense fallback={<Spinner/>}>` shows a fallback UI while that chunk loads.
**Why correct:** Connects the *why* (initial load performance) to the *how* (dynamic import + Suspense boundary).
**Common Mistakes:** Not knowing `React.lazy` only works for default exports; forgetting error boundaries are needed too (Suspense doesn't catch load failures, an ErrorBoundary does).
**Follow-up:** Where would you place code-split boundaries in a real app?
**Follow-up Answer:** At route level (each page as its own chunk via React Router lazy loading) is the highest-impact, lowest-risk split point; also for heavy, rarely-used components (rich text editors, charts, modals).
**Difficulty:** Medium
**Product companies:** Very common.

**Q42. What are Error Boundaries and their limitations?**
**Best Answer:** A class component implementing `static getDerivedStateFromError` and/or `componentDidCatch` that catches render-phase errors in its child tree and shows a fallback UI instead of a blank white screen. Limitations: doesn't catch errors in event handlers, async code, SSR, or errors in the boundary itself — those need manual `try/catch`.
**Why correct:** The limitations list is the actual interview trap — many candidates think Error Boundaries catch everything.
**Common Mistakes:** Believing Error Boundaries catch async/event-handler errors; not knowing they must be class components (no hook equivalent yet).
**Follow-up:** How do you handle an error thrown inside an `onClick` handler, then?
**Follow-up Answer:** Wrap in `try/catch` manually and either set local error state to render fallback UI, or use a library like `react-error-boundary`'s `useErrorHandler` to re-throw it into the render phase so the boundary catches it.
**Difficulty:** Medium
**Product companies:** Common.

**Q43. What causes unnecessary re-renders in React and how do you fix them (general performance strategy)?**
**Best Answer:** Causes: parent re-renders cascading to all children by default, new object/array/function references passed as props each render, context changes triggering all consumers, unkeyed/poorly-keyed lists. Fixes: `React.memo` for pure components, `useMemo`/`useCallback` for referential stability, splitting state/context to narrow re-render scope, virtualization for long lists, and profiling with React DevTools Profiler before optimizing (measure, don't guess).
**Why correct:** Ends with "measure before optimizing," which is the senior-engineer instinct interviewers specifically listen for.
**Common Mistakes:** Reflexively wrapping everything in `memo`/`useMemo` without profiling first (premature optimization, sometimes net-negative).
**Follow-up:** How would you find which component is re-rendering unnecessarily in a real app?
**Follow-up Answer:** React DevTools Profiler — record an interaction, inspect the flamegraph for components that rendered without prop/state changes ("why did this render" highlighting), then apply targeted memoization.
**Difficulty:** Hard
**Product companies:** Extremely common in senior rounds.

---

## Node.js

**Q44. How does Node.js achieve non-blocking I/O on a single thread?**
**Best Answer:** Node uses the libuv event loop: I/O operations (file, network, DB) are delegated to the OS/worker thread pool, and Node continues executing other JS. When the I/O completes, its callback is queued back onto the event loop's phases (timers, pending callbacks, poll, check, close) to run on the main thread.
**Why correct:** Names libuv and the phase-based loop, showing real depth vs "Node is async."
**Common Mistakes:** Saying Node is "multi-threaded" for I/O the way JS execution is (JS execution itself is single-threaded; only the underlying I/O/thread pool is parallel).
**Follow-up:** What happens if you run a CPU-heavy synchronous loop in a Node request handler?
**Follow-up Answer:** It blocks the single JS thread entirely — no other requests can be processed until it finishes. Fix: offload to a Worker Thread, a child process, or a queue/microservice for CPU-heavy work.
**Difficulty:** Medium
**Product companies:** Very common for full-stack roles.

**Q45. Explain Express middleware and the request-response cycle.**
**Best Answer:** Middleware are functions `(req, res, next)` that run in registration order, can modify `req`/`res`, and must call `next()` to pass control forward (or send a response to end the cycle). Used for logging, auth, body parsing, error handling. Error-handling middleware has 4 params `(err, req, res, next)` and is placed last.
**Why correct:** Explicitly notes error middleware's 4-arg signature and placement — a real Express-specific detail interviewers check.
**Common Mistakes:** Forgetting to call `next()` (hangs the request); putting error middleware before routes.
**Follow-up:** How do you handle async errors in an Express route without crashing the process?
**Follow-up Answer:** Wrap the handler in `try/catch` and call `next(err)`, or use a helper wrapper (`express-async-handler`) that automatically forwards rejected promises to the error middleware — without this, an unhandled rejection in an async route silently fails or crashes older Express versions.
**Difficulty:** Medium
**Product companies:** Very common.

**Q46. Explain JWT-based authentication and authorization end to end.**
**Best Answer:** Auth: user logs in with credentials → server verifies → issues a signed JWT (header.payload.signature) containing user id/roles, sent to client. Client stores it (ideally httpOnly cookie) and sends it on each request (`Authorization: Bearer <token>` or auto-via cookie). Server verifies the signature (not a DB lookup) on each request via middleware to authenticate. Authorization is separate: after authenticating *who* they are, check their role/permissions claim in the token (or a DB lookup) to decide *what* they can access.
**Why correct:** Clearly separates authentication (who) from authorization (what), a distinction interviewers explicitly probe.
**Common Mistakes:** Conflating authN and authZ; storing sensitive data unencrypted in the JWT payload (it's base64, not encrypted — anyone can decode and read it).
**Follow-up:** JWTs are stateless — how do you handle logout or token revocation before expiry?
**Follow-up Answer:** True stateless JWTs can't be revoked directly; solutions: short expiry + refresh tokens (revoke the refresh token server-side), maintain a server-side denylist/blacklist of revoked token IDs checked on each request, or store session state in Redis for near-stateless-but-revocable auth.
**Difficulty:** Hard
**Product companies:** Extremely common, esp. Razorpay/fintech.

**Q47. What is CORS and why does the browser enforce it?**
**Best Answer:** CORS (Cross-Origin Resource Sharing) is a browser security mechanism enforcing the Same-Origin Policy — by default a page can't make requests to a different origin (scheme+host+port). The server opts in by sending `Access-Control-Allow-Origin` (and related headers) in its response; for non-simple requests (custom headers, non-GET/POST), the browser first sends an OPTIONS preflight request to check permission before the real request.
**Why correct:** Correctly frames CORS as a *browser-enforced, server-configured* policy — not a server-side security feature (a common misconception).
**Common Mistakes:** Thinking CORS protects the server (it protects the *user's browser* from malicious cross-origin JS misusing their credentials); setting `Access-Control-Allow-Origin: *` with credentials enabled (invalid combination).
**Follow-up:** Your API works via Postman but fails with a CORS error from the browser. Why, and how do you fix it?
**Follow-up Answer:** Postman isn't a browser — it doesn't enforce CORS, so the request succeeds there regardless of headers. Fix: configure the server's `cors` middleware to allow the frontend's origin explicitly (and `credentials: true` if cookies are used).
**Difficulty:** Medium
**Product companies:** Very common.

**Q48. How do you manage environment variables and secrets safely?**
**Best Answer:** Use `.env` files (via `dotenv`) for local dev, never commit them (`.gitignore`), and inject real secrets via the hosting platform's secret manager (AWS Secrets Manager, Vercel/Render env vars, k8s secrets) in production. Validate required env vars at startup (fail fast) rather than discovering a missing key mid-request.
**Why correct:** Adds the "fail fast at startup" practice, a concrete senior-level habit beyond just "use dotenv."
**Common Mistakes:** Committing `.env` to git; hardcoding secrets in source; not validating env vars exist before the app starts serving traffic.
**Follow-up:** How do you expose a *safe subset* of env vars to a frontend build (e.g., Vite/CRA) without leaking backend secrets?
**Follow-up Answer:** Use the framework's explicit public-prefix convention (`VITE_*`, `NEXT_PUBLIC_*`) — only variables with that prefix get bundled into client JS; everything else stays server-only by design.
**Difficulty:** Easy
**Product companies:** Common.

**Q49. How do you handle file uploads in a Node/Express + React app?**
**Best Answer:** Frontend: `<input type="file">`, build a `FormData` object, POST via fetch/axios with `multipart/form-data` (browser sets the boundary automatically — don't manually set Content-Type). Backend: use `multer` middleware to parse multipart data, validate file type/size server-side (never trust client-side checks alone), store to disk/S3, save the reference URL in the DB.
**Why correct:** Flags the classic bug (manually setting `Content-Type` breaks the multipart boundary) and the security point (server-side validation is mandatory).
**Common Mistakes:** Manually setting `Content-Type: multipart/form-data` header (missing the boundary breaks parsing); trusting client-side file-type checks as a security boundary.
**Follow-up:** How would you handle uploading a 2GB video file reliably?
**Follow-up Answer:** Don't proxy the whole file through your Node server — use direct-to-S3 uploads via a pre-signed URL (client uploads straight to S3), or chunked/resumable uploads (e.g., tus protocol) to survive network drops.
**Difficulty:** Medium
**Product companies:** Common.

**Q50. What's your general error-handling strategy in a Node backend?**
**Best Answer:** Centralize error handling in one Express error middleware; use custom error classes (`AppError` with `statusCode`, `isOperational`) to distinguish expected errors (validation, 404) from programmer bugs; log unexpected errors with stack traces (via a logger like Winston/Pino, not `console.log`); never leak stack traces to the client in production; catch unhandled promise rejections/exceptions at the process level as a last-resort safety net (and still crash+restart for unknown errors, since state may be corrupted).
**Why correct:** Distinguishes operational vs programmer errors — the actual production-grade pattern (from Node best-practice guides) interviewers look for.
**Common Mistakes:** Wrapping every route in ad-hoc try/catch with duplicated logic instead of centralizing; leaking stack traces to clients.
**Follow-up:** Should you keep a Node process alive after an uncaught exception?
**Follow-up Answer:** Generally no for unknown/programmer errors — the process may be in a corrupted state; log it, then gracefully shut down (stop accepting new connections, finish in-flight ones) and let a process manager (PM2/k8s) restart it, rather than `process.on('uncaughtException')` silently swallowing and continuing.
**Difficulty:** Hard
**Product companies:** Common in senior backend rounds.

---

## MongoDB

**Q51. Collections vs Documents — how does MongoDB's schema-less model differ from SQL?**
**Best Answer:** A collection is analogous to a SQL table; a document (BSON, JSON-like) is analogous to a row, but documents in the same collection can have different fields (schema-less/flexible) and support nested objects/arrays natively — avoiding joins for naturally hierarchical data. Trade-off: no enforced schema means the application layer (or Mongoose schemas) must maintain data consistency.
**Why correct:** States the real trade-off (flexibility vs enforced consistency) rather than presenting schema-less as strictly better.
**Common Mistakes:** Claiming MongoDB has "no schema at all" in practice (most real apps use Mongoose/JSON-schema validation to enforce structure anyway).
**Follow-up:** When would you choose MongoDB over a relational DB, and vice versa?
**Follow-up Answer:** MongoDB fits rapidly-evolving schemas, deeply nested/hierarchical data, and horizontal scale needs. Relational (Postgres) fits when strong consistency, complex multi-table transactions, and relational integrity (foreign keys) matter more than flexibility.
**Difficulty:** Easy
**Product companies:** Common if MERN is on the JD.

**Q52. What is indexing in MongoDB and how does it improve performance?**
**Best Answer:** An index is a B-tree-like data structure on a field (or fields) that lets MongoDB avoid a full collection scan (`COLLSCAN`) when querying/sorting on that field, turning O(n) lookups into roughly O(log n). Trade-off: indexes speed up reads but slow down writes (every insert/update must also update the index) and consume extra storage/memory.
**Why correct:** States the actual read/write trade-off, which is what separates "I know indexes exist" from "I understand when to use them."
**Common Mistakes:** Indexing every field indiscriminately; not knowing compound index field order matters (leftmost-prefix rule).
**Follow-up:** You have a query filtering on `status` and sorting by `createdAt`. How do you design the index?
**Follow-up Answer:** A compound index `{ status: 1, createdAt: -1 }` — matches the equality-filter-then-sort pattern (ESR rule: Equality, Sort, Range), letting Mongo use the index for both the filter and the sort in one pass instead of an in-memory sort.
**Difficulty:** Medium
**Product companies:** Common.

**Q53. Explain the Aggregation Pipeline with a real example.**
**Best Answer:** The aggregation pipeline processes documents through a sequence of stages (`$match`, `$group`, `$sort`, `$project`, `$lookup`, etc.), each stage's output feeding the next — similar to a SQL `GROUP BY` + `JOIN` combined. Example: get total order value per user in the last 30 days — `$match` (date range) → `$group` (sum by userId) → `$sort` (descending) → `$limit`.
**Why correct:** Gives a concrete, realistic pipeline instead of an abstract definition, proving hands-on experience.
**Common Mistakes:** Not knowing `$match` early in the pipeline (before `$group`) is a major performance optimization since it can use indexes and reduces documents processed downstream.
**Follow-up:** How does `$lookup` work, and what's its cost compared to a SQL JOIN?
**Follow-up Answer:** `$lookup` performs a left outer join against another collection within the same pipeline. It's generally more expensive than a SQL JOIN since MongoDB isn't optimized for joins the way relational engines are — for very hot paths, denormalizing (embedding data) is often preferred over frequent `$lookup`.
**Difficulty:** Hard
**Product companies:** Common in backend-heavy rounds.

**Q54. What does `populate()` do in Mongoose, and what's a common performance trap with it?**
**Best Answer:** `populate()` replaces a referenced ObjectId field with the actual referenced document(s) — Mongoose does this by issuing a separate query behind the scenes (unlike a native SQL JOIN in one query). The trap: calling `populate()` inside a loop over many documents causes an N+1 query problem — fix by populating once on the parent query, or using `$lookup` in an aggregation for a single-query join.
**Why correct:** Explicitly names the N+1 problem and its fix — the actual production bug this causes.
**Common Mistakes:** Assuming `populate()` is a single efficient join like SQL (it's not — it's a second query under the hood).
**Follow-up:** How would you fetch a list of blog posts with their author's name in a single efficient query?
**Follow-up Answer:** `Post.find().populate('author', 'name')` — one `find` plus one batched query for all referenced authors (Mongoose batches populate across the result set, not one query per document), or use `$lookup` in an aggregation if you need it combined with other pipeline stages.
**Difficulty:** Medium
**Product companies:** Common for MERN roles.

---

## Git

**Q55. Merge vs Rebase — what's the difference and when do you use each?**
**Best Answer:** Merge creates a new merge commit combining two branch histories, preserving exact history (including all intermediate commits) — safe for shared/public branches. Rebase replays your branch's commits on top of the target branch, producing a linear history — good for cleaning up a local feature branch before opening a PR, but never rebase a branch others are already based on (rewrites commit hashes, breaking their history).
**Why correct:** States the golden rule ("never rebase shared history") which is the actual thing that causes real team incidents.
**Common Mistakes:** Not knowing rebase rewrites commit SHAs; rebasing a branch that's already pushed and shared with teammates.
**Follow-up:** You rebased a branch and now `git push` is rejected. What do you do, and is it safe?
**Follow-up Answer:** `git push --force-with-lease` — safer than plain `--force` because it fails if someone else pushed new commits you haven't seen, preventing accidentally overwriting their work.
**Difficulty:** Medium
**Product companies:** Very common.

**Q56. What does `git stash` do, and what's a real workflow using it?**
**Best Answer:** `git stash` shelves uncommitted changes (working directory + staged) onto a stack without committing, restoring a clean working tree — useful when you need to urgently switch branches (e.g., hotfix) without committing half-done work. `git stash pop` reapplies and removes it from the stack; `git stash apply` reapplies but keeps it stashed.
**Why correct:** Gives the pop-vs-apply distinction and a realistic trigger scenario (urgent branch switch).
**Common Mistakes:** Forgetting stashes are local-only (not pushed) and can be lost if not tracked; not knowing you can stash specific files (`git stash push -- <file>`).
**Follow-up:** You have multiple stashes. How do you view and apply a specific one?
**Follow-up Answer:** `git stash list` shows all stashes with indices, `git stash apply stash@{2}` applies a specific one by reference.
**Difficulty:** Easy
**Product companies:** Common.

**Q57. What is `cherry-pick` and when would you use it?**
**Best Answer:** `git cherry-pick <commit>` applies a single specific commit from one branch onto your current branch without merging the whole branch — used when you need just one fix (e.g., a hotfix committed on `develop`) applied to `main`/a release branch without pulling in unrelated in-progress commits.
**Why correct:** Names the precise real-world trigger (selective hotfix porting) rather than a vague definition.
**Common Mistakes:** Not knowing cherry-pick can cause conflicts if the target branch has diverged, or duplicate-commit confusion if the same change later gets merged normally too.
**Follow-up:** What happens if you cherry-pick a commit that depends on an earlier commit not yet in your branch?
**Follow-up Answer:** It likely fails or produces broken code/conflicts since the dependency is missing — you'd need to cherry-pick the dependent commits in order, or resolve conflicts manually.
**Difficulty:** Medium
**Product companies:** Common.

---

## REST APIs

**Q58. Explain REST HTTP methods and idempotency.**
**Best Answer:** GET (read, safe+idempotent), POST (create, not idempotent — repeating creates duplicates), PUT (full replace, idempotent — repeating gives the same end state), PATCH (partial update, not guaranteed idempotent depending on implementation), DELETE (remove, idempotent — deleting twice ends in the same "gone" state).
**Why correct:** Explicitly defines idempotency per verb — the actual concept interviewers test beyond memorized CRUD mapping.
**Common Mistakes:** Confusing PUT and PATCH (full vs partial); calling POST idempotent.
**Follow-up:** Why does idempotency matter for retry logic in unreliable networks?
**Follow-up Answer:** If a client times out and retries a PUT/DELETE, the end result is the same either way (safe to retry blindly); retrying a POST blindly could create duplicate resources, so it needs idempotency keys or dedup logic on the server.
**Difficulty:** Easy
**Product companies:** Extremely common.

**Q59. Explain common HTTP status codes and when to use them.**
**Best Answer:** 200 OK (success), 201 Created (POST success), 204 No Content (success, no body, e.g. DELETE), 400 Bad Request (invalid input), 401 Unauthorized (not authenticated), 403 Forbidden (authenticated but not allowed), 404 Not Found, 409 Conflict (e.g., duplicate resource), 422 Unprocessable Entity (validation failure), 429 Too Many Requests (rate limited), 500 Internal Server Error, 503 Service Unavailable.
**Why correct:** Groups codes by category (2xx success, 4xx client error, 5xx server error) with the actual scenario for each, not just a memorized list.
**Common Mistakes:** Conflating 401 and 403 (authentication vs authorization); returning 200 for errors with an error message in the body (breaks REST conventions and client error handling).
**Follow-up:** A user is logged in but tries to access another user's private data. What status code, and why?
**Follow-up Answer:** 403 Forbidden — they're authenticated (401 wouldn't be right), just not authorized for this specific resource.
**Difficulty:** Easy
**Product companies:** Extremely common.

**Q60. How do you design pagination, filtering, and sorting for a list API?**
**Best Answer:** Pagination: offset-based (`?page=2&limit=20`) is simple but slow/inconsistent on large, changing datasets; cursor-based (`?cursor=<lastId>&limit=20`) is more performant and stable for infinite feeds since it doesn't re-scan skipped rows. Filtering: query params per field (`?status=active&category=books`), validated server-side. Sorting: `?sort=createdAt&order=desc`, whitelist sortable fields to prevent arbitrary/expensive sorts or injection.
**Why correct:** Explicitly compares offset vs cursor pagination trade-offs, which is the real system-design-adjacent question hiding inside this topic.
**Common Mistakes:** Using offset pagination for a real-time feed (items shift as new data is inserted, causing skipped/duplicated items); not validating/whitelisting sort fields (injection/perf risk).
**Follow-up:** Why is cursor-based pagination better for an infinite-scroll social feed specifically?
**Follow-up Answer:** New posts are constantly inserted at the top; offset-based pagination recalculates position by count, causing items to shift and duplicate/skip between page loads — a cursor anchored to a specific item (e.g., last seen post's timestamp/id) stays stable regardless of new inserts.
**Difficulty:** Medium
**Product companies:** Very common.

---

# SCENARIO-BASED QUESTIONS
*Format: Approach → Why → Alternatives → Trade-offs → What the interviewer is really checking*

**S1. An API call takes 20 seconds to respond. How do you handle it on the frontend?**
**Approach:** Show a loading state immediately (skeleton > spinner for perceived performance), set a reasonable client-side timeout with `AbortController`, allow the user to cancel, and consider whether the operation should be async on the backend (return a job ID immediately, poll or use a WebSocket for the result) instead of holding the HTTP connection open.
**Why:** A 20s blocking request is almost always a backend/architecture smell, not just a frontend UX problem — the best answer addresses both layers.
**Alternatives:** Long polling, WebSocket push when done, Server-Sent Events for progress updates.
**Trade-offs:** Polling adds server load; WebSockets add infra complexity; the "return job ID + poll" pattern needs a job queue (Bull/Redis) on the backend.
**Interviewer expectation:** Do you default to "add a spinner" (junior) or question whether a 20s synchronous request is the right design (senior)?

**S2. A React component re-renders multiple times unexpectedly. How do you debug and fix it?**
**Approach:** Use React DevTools Profiler to record and see which renders are unnecessary and why ("highlight updates," "why did this render"). Check for: parent re-renders cascading down, new object/array/function props each render, unmemoized context value, missing/incorrect `key`. Fix with `React.memo`, `useMemo`/`useCallback`, splitting context, or lifting/colocating state correctly.
**Why:** Debugging methodically (profile first) is what's being tested, not just "wrap it in memo."
**Alternatives:** `why-did-you-render` library for automatic logging of re-render causes.
**Trade-offs:** Over-memoizing adds complexity and comparison cost; sometimes the right fix is restructuring state location, not adding memoization band-aids.
**Interviewer expectation:** A structured debugging process, not a guessed fix.

**S3. The backend server is down. How does the frontend handle it gracefully?**
**Approach:** Wrap API calls in try/catch, show a clear error state (not a blank screen/crash) with a retry action, implement exponential backoff for automatic retries on transient failures, and fall back to cached/stale data if available (stale-while-revalidate pattern) rather than showing nothing.
**Why:** Graceful degradation over hard failure is the actual production expectation.
**Alternatives:** Circuit breaker pattern to stop hammering a known-down service; offline banner via `navigator.onLine`.
**Trade-offs:** Showing stale data risks confusing users if not clearly labeled as such.
**Interviewer expectation:** Resilience thinking — does the UI ever show a raw crash/blank page?

**S4. The auth token expires mid-session. How do you handle it seamlessly?**
**Approach:** Use short-lived access tokens + a long-lived httpOnly refresh token. An Axios/fetch interceptor catches 401 responses, calls the refresh endpoint, retries the original failed request transparently, and only redirects to login if the refresh itself fails. Queue concurrent requests during the refresh so you don't fire multiple simultaneous refresh calls.
**Why:** The "queue concurrent requests during refresh" detail is what distinguishes a real implementation from a naive one (race condition otherwise).
**Alternatives:** Silent re-auth via a hidden iframe (older SSO pattern); fully re-fetching a session on every app load.
**Trade-offs:** Refresh tokens in httpOnly cookies are safer from XSS but need CSRF protection; longer refresh token life increases the window if it's ever compromised.
**Interviewer expectation:** Do you know this needs an interceptor + a request queue, not just "call refresh and retry"?

**S5. You need to render 1 million records in a list/table. How?**
**Approach:** Never render all 1M DOM nodes — use list virtualization (`react-window`/`react-virtualized` or `@tanstack/react-virtual`) to render only the visible viewport rows (plus a small buffer), recycling DOM nodes on scroll. Pair with server-side pagination/filtering so you're not even shipping 1M records to the client in the first place.
**Why:** The real answer is two-layered: don't fetch it all, and don't render it all — most candidates only mention one.
**Alternatives:** Windowing with fixed-height rows (simpler/faster) vs variable-height (more complex, needs measurement); canvas-based rendering for extreme cases (e.g., spreadsheets).
**Trade-offs:** Virtualization breaks native browser find-in-page (Ctrl+F) and complicates accessibility (screen readers) — needs extra handling.
**Interviewer expectation:** Virtualization keyword + acknowledging you shouldn't fetch 1M rows client-side at all.

**S6. How do you implement search optimization (search-as-you-type)?**
**Approach:** Debounce the input (300ms) to avoid firing a request per keystroke, cancel in-flight stale requests when a newer one starts (`AbortController`, or ignore out-of-order responses by request id/timestamp), and consider debounced client-side filtering for small datasets vs a backend search index (Elasticsearch/Algolia) for large ones.
**Why:** The out-of-order response race condition is the subtle bug interviewers want named.
**Alternatives:** Throttling instead of debouncing (worse UX here, fires mid-typing); using an in-memory trie/fuzzy search client-side for a small local dataset.
**Trade-offs:** Debounce delay is a UX tuning trade-off (too long feels laggy, too short doesn't reduce requests enough).
**Interviewer expectation:** Debounce + race-condition handling together, not just debounce alone.

**S7. Implement infinite scrolling.**
**Approach:** Use `IntersectionObserver` on a sentinel element at the list's bottom to detect when the user nears the end, then fetch the next page (cursor-based) and append. Combine with virtualization if the total list can grow very large, to avoid unbounded DOM growth.
**Why:** `IntersectionObserver` is the modern, performant approach vs scroll-event listeners (which fire constantly and need manual throttling).
**Alternatives:** Scroll-event + throttle (older, less efficient); "Load More" button (simpler, more accessible, better for SEO/back-button state).
**Trade-offs:** Infinite scroll harms footer accessibility/discoverability and loses scroll position on back-navigation unless handled explicitly; "Load More" trades some UX smoothness for those benefits.
**Interviewer expectation:** IntersectionObserver knowledge + honest trade-off vs pagination (see S24 below).

**S8. How do you find and fix a memory leak in a production React app?**
**Approach:** Reproduce with Chrome DevTools Memory tab — take heap snapshots before/after repeating an action many times, diff them for growing retained objects/detached DOM nodes. Common React culprits: missing `useEffect` cleanup (subscriptions, timers, event listeners), setting state after unmount.
**Why:** Concrete tool + concrete common causes shows real debugging experience, not textbook knowledge.
**Alternatives:** `why-did-you-render`/React Profiler for render-related leaks; Lighthouse memory audits.
**Trade-offs:** N/A — mostly a discipline/cleanup issue, not a design trade-off.
**Interviewer expectation:** Naming the actual Chrome DevTools workflow, not just "add cleanup functions."

**S9. How do you optimize a large JS bundle?**
**Approach:** Analyze first (`webpack-bundle-analyzer`/`vite-bundle-visualizer`) to find what's actually large. Then: code-split by route, lazy-load heavy/rarely-used components, tree-shake unused exports (ensure ESM, avoid importing whole libraries — `import { debounce } from 'lodash-es'` not the whole lodash), replace heavy dependencies with lighter alternatives, and enable compression (gzip/brotli) at the server/CDN level.
**Why:** "Measure first with an analyzer" before optimizing is the senior signal again.
**Alternatives:** Module federation/micro-frontends for very large multi-team apps; CDN-hosted common libs (React/ReactDOM) to leverage browser cache across sites (less common now with HTTP/2+).
**Trade-offs:** Aggressive code-splitting adds more network requests (mitigated by HTTP/2 multiplexing) and slightly more complexity in build config.
**Interviewer expectation:** Analyzer-first methodology + at least 3 concrete techniques.

**S10. How do you optimize large images for the web?**
**Approach:** Serve modern formats (WebP/AVIF) with a `<picture>`/fallback, responsive images via `srcset`/`sizes` so the browser downloads an appropriately-sized version per device, lazy-load offscreen images (`loading="lazy"`), compress at build/CDN time, and use a CDN with on-the-fly resizing/transformation (Cloudinary/Imgix) rather than serving one giant original everywhere.
**Why:** Combines format, responsive sizing, and lazy loading — the three independent levers, not just one.
**Alternatives:** Low-Quality Image Placeholder (blur-up) technique for perceived performance; SVG for icons/illustrations instead of raster images entirely.
**Trade-offs:** AVIF has best compression but slower encode time and slightly less universal support than WebP; CDN transformation services add cost/vendor dependency.
**Interviewer expectation:** Format + responsive sizing + lazy loading named together.

**S11. How do you add offline support to a web app?**
**Approach:** Service Worker to intercept network requests and serve cached assets/data when offline (via the Cache API), a manifest for installability (PWA), and a clear strategy per resource type: cache-first for static assets, network-first-with-fallback for dynamic data, background sync to queue actions (e.g., form submits) made while offline and replay them once back online.
**Why:** Naming per-resource-type caching strategy (not one blanket rule) shows real understanding of the trade-offs involved.
**Alternatives:** IndexedDB for larger structured offline data storage vs Cache API for request/response pairs.
**Trade-offs:** Service workers add real complexity (versioning/cache invalidation on deploy is notoriously tricky — stale cache bugs); background sync isn't supported in all browsers (Safari), needs a fallback.
**Interviewer expectation:** Service Worker + naming at least one caching strategy by name (cache-first, network-first, stale-while-revalidate).

**S12. What's your general caching strategy across an app (browser, CDN, API)?**
**Approach:** Layer it: CDN caches static assets with long `max-age` + content-hashed filenames (safe to cache "forever," invalidated by filename change on new deploys); HTTP caching headers (`Cache-Control`, `ETag`) for API responses where appropriate; client-side data caching via React Query/RTK Query (stale-while-revalidate — show cached data instantly, refetch in background); avoid caching sensitive/user-specific data at the CDN layer.
**Why:** The content-hash-for-static-assets trick is the specific mechanism that makes "cache forever" safe — worth naming explicitly.
**Alternatives:** Service worker caching (see S11) for offline-capable caching; Redis for server-side caching of expensive computed/DB results.
**Trade-offs:** Aggressive caching risks serving stale data; cache invalidation is famously one of the two hard problems in CS — need clear TTLs and invalidation triggers.
**Interviewer expectation:** A layered answer (browser/CDN/API/client-state), not just one layer.

**S13. How do you handle a race condition, e.g., two rapid API calls where the older response arrives after the newer one?**
**Approach:** Tag each request with an incrementing id/timestamp or use `AbortController` to cancel the previous in-flight request when a new one starts; on response, ignore/discard results that don't match the latest request id.
**Why:** Naming the "ignore stale response by id" pattern is the concrete fix, not just "handle race conditions carefully."
**Alternatives:** Debouncing the trigger itself to reduce how often the race can even occur (complementary, not a full fix on its own); libraries like React Query handle this automatically via query keys.
**Trade-offs:** AbortController cancels the network request but doesn't guarantee the server stops processing it — combine with idempotent server design for true safety.
**Interviewer expectation:** AbortController/request-id pattern specifically named.

**S14. How would you integrate WebSockets for real-time features?**
**Approach:** Establish a WebSocket connection (often via Socket.IO for reconnection/fallback handling) after auth, subscribe to relevant channels/rooms, update local/global state (e.g., via a reducer or query cache update) on incoming messages, and implement reconnection with backoff plus a "resync" fetch on reconnect in case messages were missed while disconnected.
**Why:** The "resync on reconnect" detail addresses the real gap — messages missed during a dropped connection — which naive implementations forget.
**Alternatives:** Server-Sent Events (SSE) for one-directional server→client updates (simpler, auto-reconnect built in, but no client→server messaging); polling as a fallback for restrictive networks/proxies blocking WebSockets.
**Trade-offs:** WebSockets need sticky sessions or a pub/sub backplane (Redis) to scale across multiple server instances; SSE is simpler but one-directional only.
**Interviewer expectation:** Reconnection + missed-message resync strategy, not just "open a socket and listen."

**S15. How do you build a real-time notification system?**
**Approach:** WebSocket (or SSE) push for connected clients, backed by a message queue/pub-sub (Redis Pub/Sub, Kafka) so notification producers (any backend service) don't need direct knowledge of which server instance holds a given user's socket connection. Persist notifications to a DB so they're available on next login even if the user was offline when sent (unread badge/count).
**Why:** The pub/sub-behind-the-sockets architecture is what makes this scale beyond a single server instance — the actual system-design layer of the question.
**Alternatives:** Polling an unread-count endpoint every N seconds (simpler, higher latency, less real-time, but far less infra complexity) — reasonable for lower-priority notifications.
**Trade-offs:** True real-time push adds meaningful infra (WS servers, pub/sub, connection scaling); polling is simpler but not instant and adds constant load.
**Interviewer expectation:** Persistence for offline users + a scaling mechanism (pub/sub), not just "use a WebSocket."

**S16. How do you implement dark mode?**
**Approach:** Define semantic CSS custom properties (`--bg`, `--text`, `--surface`) in `:root`, override them under a `[data-theme="dark"]` selector, toggle that attribute via JS, and persist the preference (localStorage) while respecting the OS-level preference by default (`prefers-color-scheme` media query) on first visit.
**Why:** CSS variables + attribute toggle is the standard scalable pattern (vs duplicating entire stylesheets or conditional class-per-component logic).
**Alternatives:** Tailwind's `dark:` variant (class-based, compiles both variants at build time); CSS-in-JS theme objects (styled-components/Emotion `ThemeProvider`).
**Trade-offs:** `prefers-color-scheme` alone (no toggle) is simplest but removes user control; must avoid a flash-of-wrong-theme on load by reading the stored preference before first paint (inline script in `<head>`).
**Interviewer expectation:** CSS variables + persistence + respecting system preference all mentioned.

**S17. How do you implement role-based access control (RBAC) in a full-stack app?**
**Approach:** Store roles/permissions in the JWT claims (or fetch on login), gate UI elements/routes on the frontend for UX (`<ProtectedRoute requiredRole="admin">`), but always re-enforce the same checks server-side on every relevant endpoint — frontend gating is UX only, never a security boundary since it can be bypassed via direct API calls.
**Why:** Explicitly stating frontend RBAC is UX-only (not security) is the critical distinction interviewers check for.
**Alternatives:** Attribute-based access control (ABAC) for more granular, context-dependent permissions vs simple role strings; a permissions matrix in the DB for dynamic role management.
**Trade-offs:** Fine-grained permissions (ABAC) are more flexible but more complex to reason about/debug than simple roles.
**Interviewer expectation:** "Frontend RBAC is UX only, backend must re-check" stated explicitly.

**S18. Design a refresh token flow in detail.**
**Approach:** On login, issue a short-lived access token (e.g., 15 min, in memory or a short-lived cookie) and a long-lived refresh token (httpOnly, secure cookie, e.g., 7 days). An interceptor catches 401s, calls `/refresh` (which validates the refresh token and issues a new access token, optionally rotating the refresh token itself for added security), retries the original request. On refresh failure, log the user out. Rotate + invalidate the old refresh token on each use (refresh token rotation) to limit damage if one is ever stolen.
**Why:** Refresh token rotation is the detail that shows awareness of real security hardening beyond the basic flow.
**Alternatives:** Sliding session (extend expiry on activity) vs fixed expiry; storing refresh tokens server-side (DB) to allow explicit revocation/"log out all devices."
**Trade-offs:** Rotation adds complexity (must handle concurrent requests reusing an old refresh token gracefully — a "grace period" is common); storing tokens server-side enables revocation but adds a DB dependency to every refresh.
**Interviewer expectation:** Full flow including rotation and the interceptor-based retry-on-401 pattern.

**S19. How would you implement optimistic UI updates?**
**Approach:** On user action (e.g., liking a post), immediately update local UI state as if the server call succeeded, fire the actual request in the background, and roll back to the previous state (plus show an error toast) if the request fails. Libraries like React Query/RTK Query support this via `onMutate` (apply optimistic change) + `onError` (rollback using the previous cached value).
**Why:** Naming the rollback-on-failure mechanism (not just "update immediately") is what makes it a complete, correct answer.
**Alternatives:** Pessimistic UI (wait for server confirmation) for high-stakes actions (payments, irreversible deletes) where a rollback would be jarring/confusing.
**Trade-offs:** Optimistic updates feel instant but risk a confusing "flicker back" on failure, and can show temporarily inconsistent data if the server rejects the change for business-logic reasons.
**Interviewer expectation:** Rollback strategy + knowing when NOT to use it (payments/critical actions).

**S20. Pagination vs Infinite Scroll — how do you decide?**
**Approach:** Choose based on content type and user intent: infinite scroll fits discovery/browsing feeds (social media, image search) where users don't need to return to a specific position; numbered pagination fits goal-directed tasks (admin tables, search results users compare/reference, e-commerce) where users need addressable pages, predictable navigation, and footer/back-button reliability.
**Why:** Ties the decision to user intent (browsing vs task-driven), not just technical preference.
**Alternatives:** "Load More" button — a middle ground giving infinite-scroll-like UX with explicit user control and better accessibility/SEO than auto-triggered infinite scroll.
**Trade-offs:** Infinite scroll harms footer visibility, back-button/scroll-position restoration, and accessibility; pagination requires the user to click through multiple times to browse deeply.
**Interviewer expectation:** A judgment call tied to product context, not "infinite scroll is always more modern/better."

**S21. When would you use React Query (or RTK Query) instead of manual `useEffect` + `fetch`?**
**Approach:** Use React Query whenever you have server state (not truly local UI state) — it handles caching, deduplication of identical in-flight requests, background refetching, stale-while-revalidate, retries, and loading/error states out of the box, eliminating a large class of hand-rolled bugs (race conditions, missing cleanup, cache invalidation) that manual `useEffect` fetching accumulates.
**Why:** Frames it as "server state is a different problem than UI state," the actual conceptual reason these libraries exist (per the React Query docs' own philosophy).
**Alternatives:** Manual `useEffect`+`fetch`/`axios` is fine for a single simple one-off call in a small app; SWR is a lighter alternative with a similar philosophy.
**Trade-offs:** Adds a dependency and a learning curve (query keys, cache invalidation mental model) — probably overkill for a tiny app with 1-2 API calls total.
**Interviewer expectation:** The "server state vs client state" framing, plus concrete features (caching, dedup, background refetch) named.

**S22. When do you reach for Redux Toolkit vs Context vs component state?**
**Approach:** Component state (`useState`) for local, single-component concerns. Lift state up / Context for state shared by a few closely-related components without high update frequency. Redux Toolkit (or Zustand) for genuinely global, frequently-updated, cross-cutting state accessed by many unrelated parts of the app, especially when you need devtools/time-travel debugging, middleware (logging, persistence), or selective re-render optimization via selectors.
**Why:** Gives a decision ladder (local → lifted/Context → global store) instead of defaulting to Redux for everything.
**Alternatives:** Zustand/Jotai as lighter-weight global state options with less boilerplate than classic Redux, increasingly preferred for new projects unless the team specifically needs Redux's ecosystem/devtools.
**Trade-offs:** Redux adds boilerplate/ceremony even with RTK; overusing global state for things that should be local causes unnecessary re-renders and coupling.
**Interviewer expectation:** A clear decision framework, awareness that Redux isn't always the default answer anymore.

**S23. SSR vs CSR vs SSG — how do you choose?**
**Approach:** CSR (client-side rendering): app shell loads, JS fetches data and renders — good for highly interactive, behind-login apps (dashboards) where SEO doesn't matter and initial load isn't as critical. SSR (server-side rendering, e.g., Next.js): HTML generated per-request on the server — good for SEO-critical, frequently-changing content (e-commerce product pages with live stock/pricing). SSG (static site generation): HTML pre-built at build time — fastest possible delivery (served from CDN), ideal for content that changes infrequently (marketing pages, blogs), often paired with ISR (Incremental Static Regeneration) to periodically refresh without a full rebuild.
**Why:** Ties each to concrete use cases (dashboard vs product page vs blog) — the actual decision interviewers want, not just definitions.
**Alternatives:** Hybrid per-route strategies within one app (Next.js lets you mix SSG/SSR/CSR per page) — the realistic modern answer rather than picking one globally.
**Trade-offs:** SSR adds server compute cost and latency per request vs SSG's near-zero cost; CSR has the worst SEO/initial-load but simplest infra (pure static file hosting + API).
**Interviewer expectation:** Per-route/hybrid thinking, and correctly mapping SEO + freshness + interactivity needs to the right choice.

**S24. What is hydration and what causes hydration mismatch errors?**
**Approach:** Hydration is the process where the client-side JS "attaches" event listeners and state to server-rendered static HTML, making it interactive, without re-rendering the DOM from scratch. A mismatch error occurs when the client's initial render output differs from the server's HTML — common causes: using `Date.now()`/`Math.random()`/`window`-dependent logic during render, or rendering different content based on `localStorage`/auth state that isn't available during SSR.
**Why:** Names concrete real causes (non-deterministic render, browser-only APIs) rather than a vague "client and server don't match."
**Alternatives:** Guard browser-only logic behind `useEffect` (runs client-only, after hydration) or a mounted-state check to defer that render until after hydration completes.
**Trade-offs:** Deferring content to post-hydration (to avoid mismatches) can cause a visible content flash/layout shift — a real UX trade-off to manage deliberately.
**Interviewer expectation:** At least one concrete cause + the `useEffect`/mounted-guard fix pattern.

**S25. How do you make accessibility improvements to an existing, non-accessible app without a full rewrite?**
**Approach:** Audit first with axe DevTools/Lighthouse to find concrete violations, prioritize by impact: keyboard navigation and focus management (biggest wins first), semantic HTML fixes (swap divs for proper landmarks/buttons), color contrast fixes (usually a quick CSS token change), then ARIA labels for custom widgets (dropdowns, modals, tabs) last, since native semantics should be fixed before reaching for ARIA.
**Why:** Prioritized, audited approach shows how to tackle this incrementally in a real legacy codebase rather than "just add ARIA everywhere."
**Alternatives:** Automated linting (`eslint-plugin-jsx-a11y`) added to CI to prevent regressions going forward, paired with periodic manual screen-reader testing (automated tools only catch ~30-40% of real issues).
**Trade-offs:** Full compliance (WCAG AA/AAA) across a large legacy app is a significant, ongoing investment — realistic answer acknowledges you triage by user impact, not fix everything at once.
**Interviewer expectation:** Audit-first + prioritization, mention of both automated and manual testing.

**S26. How do you handle cross-browser compatibility issues?**
**Approach:** Use Autoprefixer/PostCSS for CSS vendor prefixes, Babel + browserslist config for JS transpilation targeting your actual supported browser matrix (check real user analytics, not assumptions), feature-detect with `@supports`/`if ('IntersectionObserver' in window)` rather than browser-sniffing (user agents are unreliable/spoofable), and use a tool like BrowserStack or actual device testing for the browsers real users use (often includes older Safari on iOS, which lags web platform features).
**Why:** "Feature detection over browser sniffing" is the specific correct engineering practice interviewers listen for.
**Alternatives:** Polyfills (`core-js`) for missing JS features on older browsers; progressive enhancement (base experience works everywhere, enhanced features layer on for capable browsers) as an overall philosophy.
**Trade-offs:** Supporting very old browsers (legacy Safari/IE-era) bloats bundle size (polyfills) and limits which modern APIs/CSS you can use directly — decide the supported matrix based on actual analytics, not guesswork.
**Interviewer expectation:** Feature detection + browserslist/Autoprefixer named, plus a data-driven (not assumed) supported-browser matrix.

---

*This document covers 60 core Q&As + 26 scenario deep-dives = 86+ distinct interview questions, each expandable in a live follow-up. Use it as a final skim, not first-time learning material.*
