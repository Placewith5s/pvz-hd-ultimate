name: Bug report
about: Report a bug
labels: bug

body:
- type: textarea
  attributes:
    label: Steps To Reproduce
    description: "How do you trigger this bug? Please walk us through it step by step."
    value: |
    1.
    2.
    3.
    ...
    render: bash
    validations:
      required: true

- type: textarea
  attributes:
    label: Behaviors
    description: "Expected and actual."
    value: ""
    render: bash
    validations:
      required: true

- type: textarea
  attributes:
    label: Workaround
    value: ""
    render: bash
    validations:
      required: true

- type: dropdown
  id: device
  attributes:
    label: Device
    options:
    - Windows 11 Pro 24H2
    - Windows 10 Home 22H2
    render: bash
    validations:
      required: true

  - type: dropdown
  id: mod-version
  attributes:
    label: Mod Version
    options:
    - v2.0.0-beta
    render: bash
    validations:
      required: true
